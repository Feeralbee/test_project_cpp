#include "readers/txt.h"
#include "ui/input.h"
#include "ui/language.h"
#include "ui/notifications.h"
#include "ui/text.h"

int main(int argc, char *argv[])
{
    ui::language::id program_language = ui::language::id::english;

    if (argc > 1 && std::string(argv[1]) == "-ru")
    {
        program_language = ui::language::id::russian;
    }

    ui::notifications notification(program_language);

    notification.output(ui::notifications_id::enter_file_path);

    auto file_path = ui::input::file_path();

    std::optional<std::vector<std::wstring>> strings_from_text;

    if (file_path.extension() == ".txt")
    {
        readers::txt user_file;
        strings_from_text = user_file.get_strings_from_file(file_path);
    }

    if (strings_from_text != std::nullopt)
    {
        notification.output(ui::notifications_id::file_has_openned);
        ui::text data;
        data.output(strings_from_text.value());
    }
    else
    {
        notification.output(ui::notifications_id::file_wasnt_found);
    }
    return 0;
}
