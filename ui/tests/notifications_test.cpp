#include "gtest/gtest.h"

#include "ui/language.h"
#include "ui/notifications.h"
namespace ui
{
class notifications_test : public notifications
{
  public:
    notifications_test(language::id test_language) : notifications(test_language)
    {
    }
    std::string get_notification(notifications_id index_of_notification)
    {
        return strings(index_of_notification);
    }
};
}

// Output notifications in english
ui::notifications_test notifications_in_english(ui::language::id::english);
TEST(output_notifications_in_english, enter_file_path)
{
    ASSERT_EQ(u8"Enter file path: ", notifications_in_english.get_notification(ui::notifications_id::enter_file_path));
}

TEST(output_notifications_in_english, file_has_openned)
{
    ASSERT_EQ(u8"File has openned!\n",
              notifications_in_english.get_notification(ui::notifications_id::file_has_openned));
}

TEST(output_notifications_in_english, file_wasnt_found)
{
    ASSERT_EQ(u8"Error! The file was not found by this path!",
              notifications_in_english.get_notification(ui::notifications_id::file_wasnt_found));
}

// Output notifications in russian
ui::notifications_test notifications_in_russian(ui::language::id::russian);
TEST(output_notifications_in_russian, enter_file_path)
{
    ASSERT_EQ("Введите путь к файлу: ",
              notifications_in_russian.get_notification(ui::notifications_id::enter_file_path));
}

TEST(output_notifications_in_russian, file_has_openned)
{
    ASSERT_EQ("Файл открылся!\n", notifications_in_russian.get_notification(ui::notifications_id::file_has_openned));
}

TEST(output_notifications_in_russian, file_wasnt_found)
{
    ASSERT_EQ("Ошибка! По данному пути файл не найден!",
              notifications_in_russian.get_notification(ui::notifications_id::file_wasnt_found));
}
