#include "readers/data.h"
#include "readers/factory.h"
#include "readers/json.h"
#include "readers/txt.h"
#include "ui/input.h"
#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/text.h"

#include <filesystem>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>

std::string parse_language_argument(int argc, char *argv[])
{
    if (argc > 0 && std::string(argv[1]) == "-ru")
    {
        return "russian";
    }
    else
        return "english";
}

int main(int argc, char *argv[])
{
    const auto language_argument = parse_language_argument(argc, argv);

    std::unique_ptr<ui::notifications> notification(ui::notifications_factory::make(language_argument));

    ui::text::output(notification->get_string(ui::notifications_id::enter_file_path));

    const auto file_path = ui::input::file_path();

    std::unique_ptr<readers::data> reader(readers::factory::create(file_path));
    if (reader != nullptr)
    {
        const std::optional<std::vector<std::wstring>> strings_from_text = reader->get_content_from_file();
        if (strings_from_text != std::nullopt)
        {
            ui::text::output(notification->get_string(ui::notifications_id::file_has_openned));
            ui::text::output(strings_from_text.value());
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
