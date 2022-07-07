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
    auto &language = ui::options::get_options();
    const auto lang = language.get_language();
    if (lang == language_id::russian)
    {
        return std::make_unique<notifications_rus>(notifications_rus());
    }
    else
    {
        return std::make_unique<notifications_en>(notifications_en());
    }
}
}
