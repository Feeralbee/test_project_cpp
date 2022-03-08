#include "language.h"
#include "program_notifications.h"

#include <string>
#include <iostream>

void output_notifications_with_endl(language language, notifications_and_errors index_of_notification)
{
	std::cout << notifications(language, index_of_notification) << std::endl;
}

void output_notifications(language language, notifications_and_errors index_of_notification)
{
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
			message = "Enter file path: ";
			break;
		case notifications_and_errors::file_has_openned:
			message = "File has openned!";
			break;
		case notifications_and_errors::path_incorrectly:
			message = "Error! The path to the file is entered incorrectly!";
			break;
		}
		break;
	case language::russian:
		switch (index_of_notification)
		{
		case notifications_and_errors::enter_file_path:
			message = "Вы выбрали русский язык. Введите путь к файлу: ";
			break;
		case notifications_and_errors::file_has_openned:
			message = "Файл открылся!";
			break;
		case notifications_and_errors::path_incorrectly:
			message = "Ошибка! Путь к файлу введен неправильно!";
			break;
		}
		break;
	case language::unknown:
		switch (index_of_notification)
		{
		case notifications_and_errors::welcome_phrase:
			message = "Hi! If you want to change russian language, write yes, else no: ";
			break;
		case notifications_and_errors::enter_file_path:
			message = "Error! You entered an incorrect value! Language - english. Enter file path: ";
			break;
		}
		break;
	}
	return message;
}