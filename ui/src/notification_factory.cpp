#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/notifications_en.h"
#include "ui/notifications_rus.h"

#include <memory>
#include <string>

namespace ui
{
std::unique_ptr<notifications> notifications_factory::make(std::string argument)
{
    if (argument == "russian")
    {
        return std::make_unique<notifications_rus>(notifications_rus());
    }
    else
    {
        return std::make_unique<notifications_en>(notifications_en());
    }
}
}
