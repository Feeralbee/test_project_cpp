#include "readers/data.h"
#include "readers/factory.h"
#include "readers/json.h"
#include "readers/txt.h"
#include "ui/input.h"
#include "ui/language.h"
#include "ui/notifications.h"
#include "ui/text.h"

#include <filesystem>
#include <memory>
#include <optional>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    ui::language::id program_language = ui::language::id::english;

    if (argc > 1 && std::string(argv[1]) == "-ru")
    {
        program_language = ui::language::id::russian;
    }

    ui::notifications notification(program_language);

    notification.output(ui::notifications_id::enter_file_path);

    const auto file_path = ui::input::file_path();

    std::unique_ptr<readers::data> reader(readers::factory::create(file_path));
    if (reader != nullptr)
    {
        const std::optional<std::vector<std::wstring>> strings_from_text = reader->get_content_from_file();
        if (strings_from_text != std::nullopt)
        {
            notification.output(ui::notifications_id::file_has_openned);
            ui::text::output(strings_from_text.value());
        }
        else
        {
            notification.output(ui::notifications_id::file_wasnt_found);
        }
    }
    else
    {
        notification.output(ui::notifications_id::file_extension_incorrect);
    }
    return 0;
}
