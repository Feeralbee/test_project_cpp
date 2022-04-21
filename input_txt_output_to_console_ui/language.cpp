#include "language.h"

#include <iostream>
#include <string>

std::string input_user_language()
{
    std::string user_selection;
    std::cin >> user_selection;
    return user_selection;
}

language interface_language_selection(std::string user_selection)
{
    language language;
    if (user_selection == "Y")
    {
        language = language::russian;
    }
    else if (user_selection == "n")
    {
        language = language::english;
    }
    else
    {
        language = language::unknown;
    }
    return language;
}