#include "readers/txt.h"

#include <filesystem>
#include <fstream>
#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace readers
{
txt::txt(const std::filesystem::path &file_path)
{
    _path = std::make_unique<std::filesystem::path>(file_path);
}
std::unique_ptr<std::vector<std::wstring>> txt::get_content_from_file()
{
    std::wifstream file_handler(*_path);
    if (file_handler.is_open())
    {
        std::unique_ptr<std::vector<std::wstring>> result = std::make_unique<std::vector<std::wstring>>();
        read(file_handler, *result);
        file_handler.close();
        return result;
    }
    else
    {
        return nullptr;
    }
}

void txt::read(std::wistream &file_handler, std::vector<std::wstring> &text_from_file)
{
    std::wstring text;
    while (std::getline(file_handler, text))
    {
        text_from_file.push_back(text);
    }
}
}
