#include "language.h"
#include "program_notifications.h"

#include <string>
#include <iostream>

void output_notifications_with_endl(language language, notifications_and_errors index_of_notification)
{
	platform::init_out();
	std::cout << notifications(language, index_of_notification) << std::endl;
}

void output_notifications(language language, notifications_and_errors index_of_notification)
{
	platform::init_out();
	std::cout << notifications(language, index_of_notification);
}

std::string notifications(language language, notifications_and_errors index_of_notification)
{
	std::string message;

	switch (language)
	{
	case language::english:
		switch (index_of_notification)
		{
		case notifications_and_errors::enter_file_path:
			message = u8"Enter file path: ";
			break;
		case notifications_and_errors::file_has_openned:
			message = u8"File has openned!";
			break;
		case notifications_and_errors::path_incorrectly:
			message = u8"Error! The path to the file is entered incorrectly!";
			break;
		}
		break;
	case language::russian:
		switch (index_of_notification)
		{
		case notifications_and_errors::enter_file_path:
			message = u8"Вы выбрали русский язык. Введите путь к файлу: ";
			break;
		case notifications_and_errors::file_has_openned:
			message = u8"Файл открылся!";
			break;
		case notifications_and_errors::path_incorrectly:
			message = u8"Ошибка! Путь к файлу введен неправильно!";
			break;
		}
		break;
	case language::unknown:
		switch (index_of_notification)
		{
		case notifications_and_errors::welcome_phrase:
			message = u8"Hi! Do you want select Russian language? [Y/n]: ";
			break;
		case notifications_and_errors::enter_file_path:
			message = u8"Error! You entered an incorrect value! Language - english. Enter file path: ";
			break;
		}
		break;
	}
	return message;
}