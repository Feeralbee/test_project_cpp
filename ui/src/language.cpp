#include "ui/language.h"

#include <string>

language parse_language_argument(int argc, char *argv[])
{
    language lang = language::english;
    if (argc > 1)
    {
        if (std::string(argv[1]) == "-ru")
            lang = language::russian;
    }
    return lang;
}
