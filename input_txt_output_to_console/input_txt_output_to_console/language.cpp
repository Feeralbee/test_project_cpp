#include "language.h"
#include "errors.h"
#include "system_notifications.h"

#include <iostream>
#include <string>


language choice_of_interface_language()
{
    std::string system_language;
    for (;;)
    {
        std::cin >> system_language;
        if (system_language == "Русский" or system_language == "русский")
        {
            notification_about_choice_of_language(language::russian);
            return language::russian;
        }
        else if (system_language == "English" or system_language == "english")
        {
            notification_about_choice_of_language(language::english);
            return language::english;
        }
        else
        {
            language_input_error();
        }
    }
}