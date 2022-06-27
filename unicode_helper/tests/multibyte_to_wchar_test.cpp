#include "unicode_helper/multibyte_to_wchar.h"

#include <gtest/gtest.h>
#include <string>

TEST(converting_string, to_wstring)
{
    ASSERT_EQ(L"string", unicode_helper::multibyte_to_wchar("string"));
}
