#include "ui/cmd_parsers.h"
#include "ui/options.h"

#include <string>
namespace ui
{
namespace cmd
{
void parse_language(int argc, char *argv[])
{
    auto &language = ui::options::get_options();
    if (argc > 1 && std::string(argv[1]) == "-ru")
        language.set_language(options::language_id::russian);
}
}
}