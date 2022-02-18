#include <iostream>
#include <string>
#include "errors.h"
#include "system_notifications.h"


bool choice_of_interface_language()
{
        std::string system_language;
        std::cin >> system_language;
        if (system_language == "Русский" or system_language == "русский")
        {
            notification_about_choice_of_russian_language();
            return true;
        }
        else if (system_language == "English" or system_language == "english")
        {
            notification_about_choice_of_english_language();
            return false;
        }
        else
        {
            language_input_error();
            return 0;
        }
}