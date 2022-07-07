#include "ui/options.h"

#include <gtest/gtest.h>

TEST(set_and_get_language, russian)
{
    auto &test = ui::options::get_options();
    test.set_ru_language();
    ASSERT_EQ(ui::language_id::russian, test.get_language());
}

TEST(set_and_get_language, english)
{
    auto &test = ui::options::get_options();
    test.set_en_language();
    ASSERT_EQ(ui::language_id::english, test.get_language());
}
