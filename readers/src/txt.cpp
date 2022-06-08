﻿#include "readers/txt.h"
#include <codecvt>

namespace readers
{
std::optional<std::vector<std::wstring>> txt::get_strings_from_file(std::filesystem::path file_path)
{
    std::optional<std::vector<std::wstring>> result;
    std::wifstream file_handler;
    file_handler.open(file_path);
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
    while (getline(file_handler, text))
    {
        strings_of_text.push_back(text);
    }
    return strings_of_text;
}

}