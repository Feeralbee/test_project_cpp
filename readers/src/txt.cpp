#include "readers/txt.h"

namespace readers
{
txt::txt(std::string file_name_to_read)
{
    FileHandler.open(file_name_to_read);
    if (FileHandler.is_open())
    {
        std::string text;
        while (getline(FileHandler, text))
        {
            strings_of_text.push_back(text);
        }
    }
    else
    {
        strings_of_text.push_back(std::nullopt);
    }
    FileHandler.close();
}

std::vector<std::optional<std::string>> txt::get_strings()
{
    return strings_of_text;
}

}