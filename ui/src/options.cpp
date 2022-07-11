#include "ui/options.h"

#include <string>

namespace ui
{
options::language_id options::get_language()
{
    return _language;
}

options &options::get_options()
{
    static options obj;
    return obj;
}

void options::set_language(language_id lang)
{
    _language = lang;
}
}
