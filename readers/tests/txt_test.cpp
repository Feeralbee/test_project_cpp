#include "readers/txt.h"

#include <gtest/gtest.h>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace readers
{
class txt_test : public txt
{
  public:
    txt_test()
    {
    }
    std::vector<std::wstring> get_read(std::wistream &file_handler)
    {
        return read(file_handler);
    }
};
}

// read_strings
TEST(read_strings, 1_string)
{
    readers::txt_test test;
    std::wstringstream file;
    file << L"1111";
    const auto result = test.get_read(file);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"1111", result[0]);
}

TEST(read_strings, 2_strings)
{
    readers::txt_test test;
    std::wstringstream file;
    file << L"1111" << std::endl << L"2222";
    const auto result = test.get_read(file);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"1111", result[0]);
    ASSERT_EQ(L"2222", result[1]);
}

TEST(read_strings, 4_strings_with_empty_string_at_top)
{
    readers::txt_test test;
    std::wstringstream file;
    file << std::endl << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl;
    std::vector<std::wstring> vector_file = {L"", L"2222", L"3333", L"4444"};
    const auto result = test.get_read(file);
    ASSERT_EQ(4, result.size());
    ASSERT_EQ(L"", result[0]);
    ASSERT_EQ(L"2222", result[1]);
    ASSERT_EQ(L"3333", result[2]);
    ASSERT_EQ(L"4444", result[3]);
}

TEST(read_strings, 5_strings_with_empty_string_at_middle)
{
    readers::txt_test test;
    std::wstringstream file;
    file << L"1111" << std::endl << "2222" << std::endl << std::endl << "3333" << std::endl << "4444" << std::endl;
    const auto result = test.get_read(file);
    ASSERT_EQ(5, result.size());
    ASSERT_EQ(L"1111", result[0]);
    ASSERT_EQ(L"2222", result[1]);
    ASSERT_EQ(L"", result[2]);
    ASSERT_EQ(L"3333", result[3]);
    ASSERT_EQ(L"4444", result[4]);
}

TEST(read_strings, 4_strings_with_empty_string_at_end)
{
    readers::txt_test test;
    std::wstringstream file;
    file << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl << std::endl;
    const auto result = test.get_read(file);
    ASSERT_EQ(4, result.size());
    ASSERT_EQ(L"2222", result[0]);
    ASSERT_EQ(L"3333", result[1]);
    ASSERT_EQ(L"4444", result[2]);
    ASSERT_EQ(L"", result[3]);
}

// get strings from file
TEST(get_strings_from_file, input_invalid_file_path)
{
    readers::txt_test test;
    const std::filesystem::path invalid_file_path = "invalid_file_path.txt";
    ASSERT_EQ(std::nullopt, test.get_content_from_file(invalid_file_path));
}

TEST(get_strings_from_file, input_correct_file_path)
{
    readers::txt_test test;
    const std::filesystem::path correct_file_path = "test_files/text.txt";
    std::wstringstream file;
    file << u8"line 1" << std::endl << u8"line 2" << std::endl << u8"line 3";
    ASSERT_EQ(test.get_read(file), test.get_content_from_file(correct_file_path).value());
}

TEST(get_strings_from_file, input_correct_file_path_in_russian)
{
    readers::txt_test test;
    const std::filesystem::path correct_file_path = "test_files/текст.txt";
    const auto result = test.get_content_from_file(correct_file_path).value();
    std::wstringstream file;
    file << u8"линия 1" << std::endl << u8"линия 2" << std::endl << u8"линия 3";
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(test.get_read(file), result);
}
