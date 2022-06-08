#include "ui/text.h"

namespace ui
{
void text::output(std::vector<std::wstring> transmitted_strings_from_text)
{
    for (std::wstring text : transmitted_strings_from_text)
    {
        std::wstring str = text;
        std::wcout << str << "\n";
    }
}
}
