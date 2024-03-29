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
    txt_test(std::filesystem::path path) : txt(path)
    {
    }
    void get_read(std::wistream &file_handler, std::vector<std::wstring> &arr_of_wstrings)
    {
        read(file_handler, arr_of_wstrings);
    }
};
}

// read_strings
TEST(read_strings, 1_string)
{
    readers::txt_test test("");
    std::wstringstream file;
    file << L"1111";
    std::vector<std::wstring> result;
    test.get_read(file, result);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"1111", result[0]);
}

TEST(read_strings, 2_strings)
{
    readers::txt_test test("");
    std::wstringstream file;
    file << L"1111" << std::endl << L"2222";
    std::vector<std::wstring> result;
    test.get_read(file, result);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"1111", result[0]);
    ASSERT_EQ(L"2222", result[1]);
}

TEST(read_strings, 4_strings_with_empty_string_at_top)
{
    readers::txt_test test("");
    std::wstringstream file;
    file << std::endl << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl;
    std::vector<std::wstring> vector_file = {L"", L"2222", L"3333", L"4444"};
    std::vector<std::wstring> result;
    test.get_read(file, result);
    ASSERT_EQ(4, result.size());
    ASSERT_EQ(L"", result[0]);
    ASSERT_EQ(L"2222", result[1]);
    ASSERT_EQ(L"3333", result[2]);
    ASSERT_EQ(L"4444", result[3]);
}

TEST(read_strings, 5_strings_with_empty_string_at_middle)
{
    readers::txt_test test("");
    std::wstringstream file;
    file << L"1111" << std::endl << "2222" << std::endl << std::endl << "3333" << std::endl << "4444" << std::endl;
    std::vector<std::wstring> result;
    test.get_read(file, result);
    ASSERT_EQ(5, result.size());
    ASSERT_EQ(L"1111", result[0]);
    ASSERT_EQ(L"2222", result[1]);
    ASSERT_EQ(L"", result[2]);
    ASSERT_EQ(L"3333", result[3]);
    ASSERT_EQ(L"4444", result[4]);
}

TEST(read_strings, 4_strings_with_empty_string_at_end)
{
    readers::txt_test test("");
    std::wstringstream file;
    file << "2222" << std::endl << "3333" << std::endl << "4444" << std::endl << std::endl;
    std::vector<std::wstring> result;
    test.get_read(file, result);
    ASSERT_EQ(4, result.size());
    ASSERT_EQ(L"2222", result[0]);
    ASSERT_EQ(L"3333", result[1]);
    ASSERT_EQ(L"4444", result[2]);
    ASSERT_EQ(L"", result[3]);
}

// get strings from file
TEST(get_strings_from_file, input_invalid_file_path)
{
    readers::txt_test test("invalid_file_path.txt");
    ASSERT_EQ(nullptr, test.get_content_from_file());
}

TEST(get_strings_from_file, input_correct_file_path)
{
    readers::txt_test test("test_files/text.txt");
    std::wstringstream file;
    file << u8"line 1" << std::endl << u8"line 2" << std::endl << u8"line 3" << std::endl;
    std::vector<std::wstring> arr;
    test.get_read(file, arr);
    const auto result = test.get_content_from_file();
    ASSERT_EQ(3, result->size());
    ASSERT_EQ(arr[0], result->at(0));
    ASSERT_EQ(arr[1], result->at(1));
    ASSERT_EQ(arr[2], result->at(2));
}

TEST(get_strings_from_file, input_correct_file_path_in_russian)
{
    readers::txt_test test("test_files/�����.txt");
    std::wstringstream file;
    file << u8"����� 1" << std::endl << u8"����� 2" << std::endl << u8"����� 3" << std::endl;
    std::vector<std::wstring> arr;
    test.get_read(file, arr);
    const auto result = test.get_content_from_file();
    ASSERT_EQ(3, result->size());
    ASSERT_EQ(arr[0], result->at(0));
    ASSERT_EQ(arr[1], result->at(1));
    ASSERT_EQ(arr[2], result->at(2));
}
