#include "ui/language.h"

#include <iostream>
#include <string>

namespace ui
{
namespace language
{
id interface_language_selection(std::string user_selection)
{
    id language;
    if (user_selection == "Y" || user_selection == "y")
    {
        language = id::russian;
    }
    else
    {
        language = id::english;
    }
    return language;
}
}
}
