#include "language.h"

#include <iostream>

void output_of_welcome_phrase()
{
    std::cout << "Hi! Choose your language: ";
}

void notification_about_choice_of_language(language language)
{
    if (language == language::russian)
    {
        std::cout << "Вы выбрали русский язык" << std::endl << "Введите путь к файлу: ";
    }
    else if (language == language::english)
    {
        std::cout << "You have chosen English" << std::endl << "Enter the path to the file: ";
    }
}

void notification_about_file_openning(language language)
{
    if (language == language::russian)
    {
        std::cout << std::endl;
        std::cout << "Файл открылся!" << std::endl << std::endl;
    }
    else if (language == language::english)
    {
        std::cout << std::endl;
        std::cout << "File has openned!" << std::endl << std::endl;
    }
}
