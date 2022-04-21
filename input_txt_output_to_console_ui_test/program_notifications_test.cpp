#include "gtest/gtest.h"

#include "program_notifications.h"

TEST(output_program_notifications, notifications_in_russian)
{
	ASSERT_EQ(notifications(language::russian, notifications_and_errors::enter_file_path), "Вы выбрали русский язык. Введите путь к файлу: ");
	ASSERT_EQ(notifications(language::russian, notifications_and_errors::file_has_openned), "Файл открылся!");
	ASSERT_EQ(notifications(language::russian, notifications_and_errors::path_incorrectly), "Ошибка! Путь к файлу введен неправильно!");
}

TEST(output_program_notifications, notifications_in_english)
{
	ASSERT_EQ(notifications(language::english, notifications_and_errors::enter_file_path), "Enter file path: ");
	ASSERT_EQ(notifications(language::english, notifications_and_errors::file_has_openned), "File has openned!");
	ASSERT_EQ(notifications(language::english, notifications_and_errors::path_incorrectly), "Error! The path to the file is entered incorrectly!");
}

TEST(output_program_notifications, notifications_in_uknown)
{
	ASSERT_EQ(notifications(language::unknown, notifications_and_errors::welcome_phrase), "Hi! Do you want select Russian language? [Y/n]: ");
	ASSERT_EQ(notifications(language::unknown, notifications_and_errors::enter_file_path), "Error! You entered an incorrect value! Language - english. Enter file path: ");
}
