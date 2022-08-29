#pragma once
#include "ui/notifications.h"
#include "ui/options.h"
#include "ui/std_out.h"

#include <memory>

namespace ui
{
class notifications_factory
{
  public:
    static std::unique_ptr<notifications> make(ui::options &app_options);
    static std::unique_ptr<notifications> make();
};
}