#include "ui/text.h"
#include "ui/std_out.h"

#include <iostream>
#include <string>
#include <vector>

namespace ui
{
void text::output(const std::string &str)
{
    platform::init_out();
    std::cout << str;
}
void text::output(const std::vector<std::wstring> &transmitted_strings_from_text)
{
    for (std::wstring text : transmitted_strings_from_text)
    {
        std::wcout << text << std::endl;
    }
}
}
