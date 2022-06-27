#include "readers/txt.h"

#include <filesystem>
#include <fstream>
#include <istream>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
txt::txt(std::filesystem::path file_path) : _path(file_path)
{
}
std::optional<std::vector<std::wstring>> txt::get_content_from_file()
{
    std::optional<std::vector<std::wstring>> result;
    std::wifstream file_handler(_path);
    if (file_handler.is_open())
    {
        result = read(file_handler);
        file_handler.close();
    }
    else
    {
        result = std::nullopt;
    }
    return result;
}

std::vector<std::wstring> txt::read(std::wistream &file_handler)
{
    std::wstring text;
    std::vector<std::wstring> strings_of_text;
    while (std::getline(file_handler, text))
    {
        strings_of_text.push_back(text);
    }
    return strings_of_text;
}

}