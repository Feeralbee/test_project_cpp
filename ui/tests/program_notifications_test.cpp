#include "gtest/gtest.h"

#include "ui/language.h"
#include "ui/notifications.h"

TEST(output_program_notifications, notifications_in_russian)
{
    ASSERT_EQ(ui::notifications::strings(ui::language::id::russian, ui::notifications::id::enter_file_path),
              "Вы выбрали русский язык. Введите путь к файлу: ");
    ASSERT_EQ(ui::notifications::strings(ui::language::id::russian, ui::notifications::id::file_has_openned),
              "Файл открылся!");
    ASSERT_EQ(ui::notifications::strings(ui::language::id::russian, ui::notifications::id::path_incorrectly),
              "Ошибка! Путь к файлу введен неправильно!");
}

TEST(output_program_notifications, notifications_in_english)
{
    ASSERT_EQ(ui::notifications::strings(ui::language::id::english, ui::notifications::id::enter_file_path),
              "Enter file path: ");
    ASSERT_EQ(ui::notifications::strings(ui::language::id::english, ui::notifications::id::file_has_openned),
              "File has openned!");
    ASSERT_EQ(ui::notifications::strings(ui::language::id::english, ui::notifications::id::path_incorrectly),
              "Error! The path to the file is entered incorrectly!");
}
