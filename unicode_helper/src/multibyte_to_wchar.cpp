#include "unicode_helper/multibyte_to_wchar.h"

#include <codecvt>
#include <locale>
#include <string>

namespace unicode_helper
{
std::wstring multibyte_to_wchar(std::string str)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}
}
