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
        std::cout << "Вы выбрали русский язык" << std::endl;
        std::cout << std::endl;
    }
    else if (language == language::english)
    {
        std::cout << "You have chosen English" << std::endl;
        std::cout << std::endl;
    }
}
