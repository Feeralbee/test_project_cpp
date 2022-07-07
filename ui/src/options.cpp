#include "ui/options.h"

#include <string>

namespace ui
{
void options::set_en_language()
{
    language = language_id::english;
}
void options::set_ru_language()
{
    language = language_id::russian;
}

language_id options::get_language()
{
    return language;
}

options &options::get_options()
{
    static options obj;
    return obj;
}

}
