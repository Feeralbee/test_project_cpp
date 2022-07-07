#include "ui/notifications_en.h"
#include "ui/notifications.h"
#include "ui/std_out.h"

#include <map>
#include <string>

namespace ui
{
notifications_en::notifications_en()
{
    strings_of_notifications[notifications_id::enter_file_path] = u8"Enter file path: ";
    strings_of_notifications[notifications_id::file_has_openned] = u8"File has openned!\n";
    strings_of_notifications[notifications_id::file_wasnt_found] = u8"Error! The file was not found by this path!\n";
    strings_of_notifications[notifications_id::file_extension_incorrect] =
        u8"The entered file extension is not supported\n";
}
}
