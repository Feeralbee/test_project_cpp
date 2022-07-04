#pragma once
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
  public:
    notifications();
    virtual ~notifications() = default;
    virtual std::string get_string(notifications_id notifi_id) = 0;
};
}
