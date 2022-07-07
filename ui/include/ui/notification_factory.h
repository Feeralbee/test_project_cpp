#pragma once
#include "ui/language.h"
#include "ui/notifications.h"
#include "ui/std_out.h"

#include <memory>

namespace ui
{
class notifications_factory
{
  public:
    static std::unique_ptr<notifications> make(language lang);
};
}