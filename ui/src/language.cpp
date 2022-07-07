#include "ui/language.h"

#include <string>

namespace ui
{
language_id parse_language_argument(int argc, char *argv[])
{
    language_id lang = language_id::english;
    if (argc > 1)
    {
        if (std::string(argv[1]) == "-ru")
            lang = language_id::russian;
    }
    return lang;
}

}
