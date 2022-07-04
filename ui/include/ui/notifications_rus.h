#pragma once
#include "ui/notifications.h"

#include <map>
#include <string>

namespace ui
{
class notifications_rus : public notifications
{
  private:
    std::map<notifications_id, std::string> strings_of_notifications;

  public:
    virtual std::string get_string(notifications_id notifi_id) override;
    notifications_rus();
};
}
