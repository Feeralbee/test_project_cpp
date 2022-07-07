#include "ui/notifications.h"

#include <map>

namespace ui
{
notifications::notifications()
{
}
std::string notifications::get_string(notifications_id notifi_id)
{
    return strings_of_notifications[notifi_id];
}
}
