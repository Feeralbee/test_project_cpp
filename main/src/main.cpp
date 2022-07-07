#include "readers/data.h"
#include "readers/factory.h"
#include "readers/json.h"
#include "readers/txt.h"
#include "ui/input.h"
#include "ui/language.h"
#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/text.h"

#include <filesystem>
#include <memory>
#include <optional>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    const auto lang = parse_language_argument(argc, argv);

    auto notification = ui::notifications_factory::make(lang);

    ui::text::output(notification->get_string(ui::notifications_id::enter_file_path));

    const auto file_path = ui::input::file_path();

    auto reader = readers::factory::create(*file_path);
    if (reader != nullptr)
    {
        const auto strings_from_text = reader->get_content_from_file();
        if (strings_from_text != nullptr)
        {
            ui::text::output(notification->get_string(ui::notifications_id::file_has_openned));
            ui::text::output(*strings_from_text);
        }
        else
        {
            ui::text::output(notification->get_string(ui::notifications_id::file_wasnt_found));
        }
    }
    else
    {
        ui::text::output(notification->get_string(ui::notifications_id::file_extension_incorrect));
    }
    return 0;
}
