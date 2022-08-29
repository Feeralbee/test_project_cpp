#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/notifications_en.h"
#include "ui/notifications_rus.h"
#include "ui/options.h"

#include <memory>
#include <string>

namespace ui
{
std::unique_ptr<notifications> notifications_factory::make()
{
    return make(ui::options::get_options());
}
std::unique_ptr<notifications> notifications_factory::make(ui::options &app_options)
{
    if (app_options.get_language() == options::language_id::russian)
    {
        return std::make_unique<notifications_rus>(notifications_rus());
    }
    return std::make_unique<notifications_en>(notifications_en());
}
}
