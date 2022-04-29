#include "ui/language.h"
#include "gtest/gtest.h"

TEST(interface_language, language_selection)
{
    ASSERT_EQ(ui::language::interface_language_selection("Y"), ui::language::id::russian);
    ASSERT_EQ(ui::language::interface_language_selection("n"), ui::language::id::english);
    ASSERT_EQ(ui::language::interface_language_selection(" "), ui::language::id::english);
}