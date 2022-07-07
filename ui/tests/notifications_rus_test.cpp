#include "gtest/gtest.h"

#include "ui/notifications_rus.h"

TEST(get_notifications_ru, enter_file_path)
{
    ui::notifications_rus notifications;
    ASSERT_EQ("Введите путь к файлу: ", notifications.get_string(ui::notifications_id::enter_file_path));
}

TEST(get_notifications_rus, file_has_openned)
{
    ui::notifications_rus notifications;
    ASSERT_EQ("Файл открылся!\n", notifications.get_string(ui::notifications_id::file_has_openned));
}

TEST(get_notifications_rus, file_wasnt_found)
{
    ui::notifications_rus notifications;
    ASSERT_EQ("Ошибка! По данному пути файл не найден!\n",
              notifications.get_string(ui::notifications_id::file_wasnt_found));
}

TEST(get_notifications_rus, file_extension_incorrect)
{
    ui::notifications_rus notifications;
    ASSERT_EQ("Введенное расширение файла не поддерживается!\n",
              notifications.get_string(ui::notifications_id::file_extension_incorrect));
}
