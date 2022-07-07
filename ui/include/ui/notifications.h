#pragma once
#include <map>
#include <string>

namespace ui
{
enum class notifications_id
{
    enter_file_path,
    file_has_openned,
    file_wasnt_found,
    file_extension_incorrect,
};
class notifications
{
  protected:
    std::map<notifications_id, std::string> strings_of_notifications;

  public:
    notifications();
    virtual ~notifications() = default;
    std::string get_string(notifications_id notifi_id);
};
}
