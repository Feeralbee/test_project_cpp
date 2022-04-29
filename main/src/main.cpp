#include "ui/input.h"
#include "ui/language.h"
#include "ui/notifications.h"
#include "ui/text.h"

#include "readers/txt.h"

int main()
{
    ui::notifications::output_welcome_phrase();

    ui::language::id program_language = ui::language::interface_language_selection(ui::input::user_choice());

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