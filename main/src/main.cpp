#include "ui/input.h"
#include "ui/language.h"
#include "ui/notifications.h"
#include "ui/text.h"

#include "readers/txt.h"

int main(int argc, char *argv[])
{
    ui::language::id program_language = ui::language::id::english;

    if (argc > 1 && std::string(argv[1]) == "-ru")
    {
        program_language = ui::language::id::russian;
    }

    ui::notifications::output(program_language, ui::notifications::id::enter_file_path);

    readers::txt user_file(ui::input::file_path());

    if (user_file.get_strings()[0] != std::nullopt)
    {
        ui::notifications::output(program_language, ui::notifications::id::file_has_openned);
        auto string_of_text = user_file.get_strings();
        ui::text data(string_of_text);
        data.output();
    }
    else
    {
        ui::notifications::output(program_language, ui::notifications::id::path_incorrectly);
    }
    return 0;
}