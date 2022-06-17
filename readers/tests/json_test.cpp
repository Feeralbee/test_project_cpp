#include "readers/json.h"

#include <filesystem>
#include <gtest/gtest.h>
#include <json/json.h>
#include <sstream>
#include <string>
#include <vector>

namespace readers
{
class json_test : public json
{
  public:
    json_test()
    {
    }
    std::vector<std::wstring> get_parse(std::istream &file_handler)
    {
        return parse(file_handler);
    }
};
}

/// 1 json object convert from json to string

TEST(checking_the_parsing_from_json_to_string, json_object_containing_string_in_russian)
{
    std::stringstream test;
    test << u8R"({"name":"Брэд"})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"name\":\n\"Брэд\"", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_string)
{
    std::stringstream test;
    test << u8R"({"name":"Vlad"})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"name\":\n\"Vlad\"", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_number)
{
    std::stringstream test;
    test << u8R"({"age":17})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"age\":\n17", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_an_array_of_strings)
{
    std::stringstream test;
    test << u8R"({"names":["Jessica", "Tony"]})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"names\":\n[\n \"Jessica\",\n \"Tony\"\n]", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_an_array_of_json_objects)
{
    std::stringstream test;
    test << u8R"({"Jessica":[{"age":20, "surname":"Smith"}]})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"Jessica\":\n[\n {\n  \"age\" : 20,\n  \"surname\" : \"Smith\"\n }\n]", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_a_1_json_object)
{
    std::stringstream test;
    test << u8R"({"person":{"name":"Anna"}})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"person\":\n{\n \"name\" : \"Anna\"\n}", result[0]);
}

TEST(checking_the_parsing_from_json_to_string, json_object_containing_a_2_json_objects)
{
    std::stringstream test;
    test << u8R"({"person":{"age":17,"name":"Jessica"}})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(L"\"person\":\n{\n \"age\" : 17,\n \"name\" : \"Jessica\"\n}", result[0]);
}

/// 2 json objects convert from json to string

TEST(checking_the_parsing_from_json_to_string, 2_json_objects)
{
    std::stringstream test;
    test << u8R"({"name":"Vlad","surname":"Zhukov"})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"name\":\n\"Vlad\"", result[0]);
    ASSERT_EQ(L"\"surname\":\n\"Zhukov\"", result[1]);
}

TEST(checking_the_parsing_from_json_to_string, 2_json_object_both_contain_an_array_of_strings)
{
    std::stringstream test;
    test << u8R"({"names":["Jessica", "Tony"], "surnames":["Smith", "Soprano"]})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"names\":\n[\n \"Jessica\",\n \"Tony\"\n]", result[0]);
    ASSERT_EQ(L"\"surnames\":\n[\n \"Smith\",\n \"Soprano\"\n]", result[1]);
}

TEST(checking_the_parsing_from_json_to_string, 2_json_objects_containing_a_json_objects_each)
{
    std::stringstream test;
    test << u8R"({"Audi":{"model":"RS5"}, "Lada":{"model":"Granta"}})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"Audi\":\n{\n \"model\" : \"RS5\"\n}", result[0]);
    ASSERT_EQ(L"\"Lada\":\n{\n \"model\" : \"Granta\"\n}", result[1]);
}

TEST(checking_the_parsing_from_json_to_string, 2_json_objects_containing_a_2_json_objects_each)
{
    std::stringstream test;
    test << u8R"({"Audi":{"Power":450,"model":"RS5"}, "Lada":{"Power":106,"model":"Granta"}})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"Audi\":\n{\n \"Power\" : 450,\n \"model\" : \"RS5\"\n}", result[0]);
    ASSERT_EQ(L"\"Lada\":\n{\n \"Power\" : 106,\n \"model\" : \"Granta\"\n}", result[1]);
}

TEST(checking_the_parsing_from_json_to_string, 2_json_object_containing_an_array_each)
{
    std::stringstream test;
    test << u8R"({"driver license":[null, true], "names":["Jessica", "Tony"]})";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"driver license\":\n[\n null,\n true\n]", result[0]);
    ASSERT_EQ(L"\"names\":\n[\n \"Jessica\",\n \"Tony\"\n]", result[1]);
}

TEST(checking_the_parsing_from_json_to_string, the_result_should_be_sorted_alphabetically)
{
    std::stringstream test;
    test << "{\"bbbb\":\"bbbb\", \"aaaa\":\"aaaa\"}";
    readers::json_test testclass;
    const auto result = testclass.get_parse(test);
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(L"\"aaaa\":\n\"aaaa\"", result[0]);
    ASSERT_EQ(L"\"bbbb\":\n\"bbbb\"", result[1]);
}

// get content from json file

TEST(get_content_from_json_file, input_incorrect_file_path)
{
    readers::json_test test;
    ASSERT_EQ(std::nullopt, test.get_content_from_file("invalid_file_path.json"));
}

TEST(get_content_from_json_file, input_correct_file_path)
{
    readers::json_test test;
    const auto result = test.get_content_from_file("test_files/test.json").value();
    const std::wstring first_string =
        L"\"cars\":\n"
        L"{\n \"Audi\" : \n {\n  \"models\" : \n  [\n   \"RS6\",\n   \"RS5\",\n   \"Q8\"\n  ]\n },\n "
        L"\"Lada\" : \n {\n  \"models\" : \n  [\n   \"Granta\",\n   \"Vesta\"\n  ]\n }\n}";
    const std::wstring second_string =
        L"\"person\":\n"
        L"{\n \"Kirill\" : \n {\n  \"age\" : 16,\n  \"driver license\" : false,\n  \"surname\" : \"Lebedev\"\n },\n "
        L"\"Vlad\" : \n {\n  \"age\" : 17,\n  \"driver license\" : true,\n  \"surname\" : \"Zhukov\"\n }\n}";
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(first_string, result[0]);
    ASSERT_EQ(second_string, result[1]);
}
