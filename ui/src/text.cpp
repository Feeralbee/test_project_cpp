#include "ui/text.h"
#include "ui/std_out.h"

#include <cwchar>
#include <string>
#include <vector>

namespace ui
{
void text::output(std::vector<std::wstring> transmitted_strings_from_text)
{
    for (std::wstring text : transmitted_strings_from_text)
    {
        std::wprintf(text.c_str());
        std::wprintf(L"\n");
    }
}
}
