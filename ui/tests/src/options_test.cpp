#include "ui_test/options_helper.h"

#include <gtest/gtest.h>

TEST(set_and_get_language, russian)
{
    ui_test::options_test test;
    test.set_language(ui::options::language_id::russian);
    ASSERT_EQ(ui::options::language_id::russian, test.get_language());
}

TEST(set_and_get_language, english)
{
    ui_test::options_test test;
    test.set_language(ui::options::language_id::english);
    ASSERT_EQ(ui::options::language_id::english, test.get_language());
}

TEST(set_and_get_language, default_language_should_be_english)
{
    ui_test::options_test test;
    ASSERT_EQ(ui::options::language_id::english, test.get_language());
}
