#include "ui/options.h"

#include <gtest/gtest.h>

class options_test : public ui::options
{
  public:
    options_test() = default;
};

TEST(set_and_get_language, russian)
{
    options_test test;
    test.set_language(ui::options::language_id::russian);
    ASSERT_EQ(ui::options::language_id::russian, test.get_language());
}

TEST(set_and_get_language, english)
{
    options_test test;
    test.set_language(ui::options::language_id::english);
    ASSERT_EQ(ui::options::language_id::english, test.get_language());
}

TEST(set_and_get_language, default_language_should_be_english)
{
    options_test test;
    ASSERT_EQ(ui::options::language_id::english, test.get_language());
}
