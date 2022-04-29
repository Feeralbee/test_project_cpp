#include "ui/text.h"

namespace ui
{
text::text(std::vector<std::optional<std::string>> transmitted_strings_from_text)
{
    strings_from_text = transmitted_strings_from_text;
}

void text::output()
{
    for (std::optional<std::string> text : strings_from_text)
    {
        std::string str = text.value();
        std::cout << str << "\n";
    }
}

int TextTest::get_count_lines()
{
    return count_lines;
}

void TextTest::output()
{
    for (std::optional<std::string> text : strings_from_text)
    {
        count_lines++;
    }
}
}
