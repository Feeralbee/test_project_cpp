#include "readers/json.h"
#include "unicode_helper/multibyte_to_wchar.h"

#include <filesystem>
#include <fstream>
#include <istream>
#include <json/json.h>
#include <json/writer.h>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
json::json(std::filesystem::path file_path) : _path(file_path)
{
}
std::optional<std::vector<std::wstring>> json::get_content_from_file()
{
    std::ifstream file_handler(_path, std::ifstream::binary);
    std::optional<std::vector<std::wstring>> content;
    if (file_handler.is_open())
    {
        content = parse(file_handler);
        file_handler.close();
    }
    else
    {
        content = std::nullopt;
    }
    return content;
}
std::vector<std::wstring> json::write_content(Json::Value root)
{
    setup_builder();
    std::vector<std::wstring> content;
    for (auto node = root.begin(); node != root.end(); node++)
    {
        content.push_back(
            unicode_helper::multibyte_to_wchar(Json::writeString(_builder, node.key())) + L":\n" +
            unicode_helper::multibyte_to_wchar(Json::writeString(_builder, root.get(node.key().asCString(), root))));
    }
    return content;
}
std::vector<std::wstring> json::parse(std::istream &file_handler)
{
    Json::Value root;
    file_handler >> root;
    return write_content(root);
}
void json::setup_builder()
{
    _builder["indentation"] = " ";
    _builder["emitUTF8"] = true;
}
}
