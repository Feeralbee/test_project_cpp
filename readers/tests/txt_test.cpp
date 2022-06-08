#include "readers/txt.h"
#include "gtest/gtest.h"

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
    file << "1111";
    std::vector<std::wstring> vector_file = {L"1111"};
    ASSERT_EQ(vector_file, test.get_read(file));
}

TEST(read_strings, 2_strings)
{
    readers::txt_test test;
    std::wstringstream file;
    file << "1111" << std::endl << "2222";
    std::vector<std::wstring> vector_file = {L"1111", L"2222"};
    ASSERT_EQ(vector_file, test.get_read(file));
}

TEST(read_strings, 5_strings_with_empty_string_at_top)
{
    readers::txt_test test;
    std::wstringstream file;
    file << std::endl << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl;
    std::vector<std::wstring> vector_file = {L"", L"2222", L"3333", L"4444"};
    ASSERT_EQ(vector_file, test.get_read(file));
}

TEST(read_strings, 5_strings_with_empty_string_at_middle)
{
    readers::txt_test test;
    std::wstringstream file;
    file << "1111" << std::endl << "2222" << std::endl << std::endl << "3333" << std::endl << "4444" << std::endl;
    std::vector<std::wstring> vector_file = {L"1111", L"2222", L"", L"3333", L"4444"};
    ASSERT_EQ(vector_file, test.get_read(file));
}

TEST(read_strings, 5_strings_with_empty_string_at_end)
{
    readers::txt_test test;
    std::wstringstream file;
    file << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl << std::endl;
    std::vector<std::wstring> vector_file = {L"2222", L"3333", L"4444", L""};
    ASSERT_EQ(vector_file, test.get_read(file));
}

// get strings from file
TEST(get_strings_from_file, input_invalid_file_path)
{
    readers::txt_test test;
    std::filesystem::path invalid_file_path = "invalid_file_path.txt";
    ASSERT_EQ(std::nullopt, test.get_strings_from_file(invalid_file_path));
}

TEST(get_strings_from_file, input_correct_file_path)
{
    readers::txt_test test;
    std::filesystem::path correct_file_path = "test_files/text.txt";
    std::wstringstream file;
    file << u8"line 1" << std::endl << u8"line 2" << std::endl << u8"line 3";
    ASSERT_EQ(test.get_read(file), test.get_strings_from_file(correct_file_path).value());
}
