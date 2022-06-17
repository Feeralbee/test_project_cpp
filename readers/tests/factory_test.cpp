#include "readers/data.h"
#include "readers/factory.h"
#include "readers/json.h"
#include "readers/txt.h"

#include <filesystem>
#include <gtest/gtest.h>
#include <memory>

TEST(testing_of_creating, class_json)
{
    const std::filesystem::path json_path = "filename.json";
    const std::unique_ptr<readers::data> result(readers::factory::create(json_path));
    ASSERT_TRUE(dynamic_cast<readers::json *>(result.get()) != nullptr);
}

TEST(testing_of_creating, class_txt)
{
    const std::filesystem::path txt_path = "filename.txt";
    const std::unique_ptr<readers::data> result(readers::factory::create(txt_path));
    ASSERT_TRUE(dynamic_cast<readers::txt *>(result.get()) != nullptr);
}

TEST(testing_of_creating, input_file_name_with_incorrect_extension)
{
    const std::filesystem::path path_incorrect = "filename.incorrect";
    const std::unique_ptr<readers::data> result(readers::factory::create(path_incorrect));
    ASSERT_EQ(result, nullptr);
}
