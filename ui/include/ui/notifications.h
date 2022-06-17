#pragma once
#include "ui/language.h"
#include "ui/std_out.h"

#include <string>

namespace ui
{
enum class notifications_id
{
    enter_file_path,
    file_has_openned,
    file_wasnt_found,
};

class notifications
{
  protected:
    std::string strings(notifications_id index_of_notification);
    ui::language::id program_language;

  public:
    notifications(ui::language::id language);
    void output(notifications_id index_of_notification);
};
}