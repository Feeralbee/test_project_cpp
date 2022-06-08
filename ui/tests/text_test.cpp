#include "ui/text.h"
#include "gtest/gtest.h"
namespace ui
{
class text_test : public text
{
  private:
    int count_lines = 0;

  public:
    text_test()
    {
    }
    int get_count_lines()
    {
        return count_lines;
    }
    void output(std::vector<std::wstring> transmitted_strings_from_text)
    {
        for (std::wstring text : transmitted_strings_from_text)
        {
            count_lines++;
        }
    }
};

}
TEST(output_strings, one_string)
{
    std::wstring first_string = L"first string";
    std::vector<std::wstring> one_string = {first_string};
    ui::text_test test;
    test.output(one_string);
    ASSERT_EQ(1, test.get_count_lines());
}

TEST(output_strings, two_strings)
{
    std::wstring first_string = L"first string";
    std::wstring second_string = L"second string";
    std::vector<std::wstring> two_strings = {first_string, second_string};
    ui::text_test test;
    test.output(two_strings);
    ASSERT_EQ(2, test.get_count_lines());
}

TEST(output_strings, three_strings)
{
    std::wstring first_string = L"first string";
    std::wstring second_string = L"second string";
    std::wstring third_string = L"third string";
    std::vector<std::wstring> three_strings = {first_string, second_string, third_string};
    ui::text_test test;
    test.output(three_strings);
    ASSERT_EQ(3, test.get_count_lines());
}

TEST(output_strings, four_strings)
{
    std::wstring first_string = L"first string";
    std::wstring second_string = L"second string";
    std::wstring third_string = L"third string";
    std::wstring fourth_string = L"fourth string";
    std::vector<std::wstring> four_strings = {first_string, second_string, third_string, fourth_string};
    ui::text_test test;
    test.output(four_strings);
    ASSERT_EQ(4, test.get_count_lines());
}

TEST(output_strings, five_strings)
{
    std::wstring first_string = L"first string";
    std::wstring second_string = L"second string";
    std::wstring third_string = L"third string";
    std::wstring fourth_string = L"fourth string";
    std::wstring fivth_string = L"fivth string";
    std::vector<std::wstring> five_strings = {first_string, second_string, third_string, fourth_string, fivth_string};
    ui::text_test test;
    test.output(five_strings);
    ASSERT_EQ(5, test.get_count_lines());
}
