#include "readers/json.h"
#include "unicode_helper/multibyte_to_wchar.h"

#include <filesystem>
#include <fstream>
#include <istream>
#include <json/json.h>
#include <json/writer.h>
#include <memory>
#include <string>
#include <vector>

namespace readers
{
json::json(std::filesystem::path file_path) : _path(file_path)
{
}
std::unique_ptr<std::vector<std::wstring>> json::get_content_from_file()
{
    std::ifstream file_handler(_path, std::ifstream::binary);
    if (file_handler.is_open())
    {
        std::unique_ptr<std::vector<std::wstring>> content = std::make_unique<std::vector<std::wstring>>();
        parse(file_handler, *content);
        file_handler.close();
        return content;
    }
    else
    {
        return nullptr;
    }
}
void json::write_content(Json::Value root, std::vector<std::wstring> &content)
{
    setup_builder();
    for (auto node = root.begin(); node != root.end(); node++)
    {
        content.push_back(
            unicode_helper::multibyte_to_wchar(Json::writeString(_builder, node.key())) + L":\n" +
            unicode_helper::multibyte_to_wchar(Json::writeString(_builder, root.get(node.key().asCString(), root))));
    }
}
void json::parse(std::istream &file_handler, std::vector<std::wstring> &content)
{
    Json::Value root;
    file_handler >> root;
    write_content(root, content);
}
void json::setup_builder()
{
    _builder["indentation"] = " ";
    _builder["emitUTF8"] = true;
}
}
