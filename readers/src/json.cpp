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
json::json()
{
}
std::optional<std::vector<std::wstring>> json::get_content_from_file(std::filesystem::path file_path)
{
    std::ifstream file_handler(file_path, std::ifstream::binary);
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
    Json::StreamWriterBuilder builder;
    builder["indentation"] = " ";
    builder["emitUTF8"] = true;
    std::vector<std::wstring> content;
    for (auto node = root.begin(); node != root.end(); node++)
    {
        content.push_back(
            unicode_helper::multibyte_to_wchar(Json::writeString(builder, node.key())) + L":\n" +
            unicode_helper::multibyte_to_wchar(Json::writeString(builder, root.get(node.key().asCString(), root))));
    }
    return content;
}
std::vector<std::wstring> json::parse(std::istream &file_handler)
{
    Json::Value root;
    file_handler >> root;
    return write_content(root);
}
}
