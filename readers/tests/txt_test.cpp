#include "readers/txt.h"
#include "gtest/gtest.h"

TEST(get_strings_from_file, 4_strings)
{
    readers::txt testFile("./txt_files_to_output_test/test_en.txt");
    std::optional<std::string> string1 = u8"Should this life sometime deceive you,";
    std::optional<std::string> string2 = u8"Don’t be sad or mad at it!";
    std::optional<std::string> string3 = u8"On a gloomy day, submit:";
    std::optional<std::string> string4 = u8"Trust — fair day will come, why grieve you?";

    std::vector<std::optional<std::string>> strings_from_text = {string1, string2, string3, string4};
    ASSERT_EQ(testFile.get_strings(), strings_from_text);
}

TEST(get_strings_from_file_russian, 4strings)
{
    readers::txt testFile("./txt_files_to_output_test/test_ru.txt");
    std::vector<std::optional<std::string>> strings_from_text = {
        u8"Если жизнь тебя обманет,", u8"Не печалься, не сердись!", u8"В день уныния смирись:",
        u8"День веселья, верь, настанет."};
    ASSERT_EQ(testFile.get_strings(), strings_from_text);
}