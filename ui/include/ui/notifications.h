#pragma once
#include "language.h"
#include "std_out.h"

#include <iostream>
#include <string>

namespace ui
{
namespace notifications
{
enum class id
{
    enter_file_path,
    file_has_openned,
    path_incorrectly,
};
std::string strings(ui::language::id language, ui::notifications::id index_of_notification);
void output(ui::language::id language, ui::notifications::id index_of_notification);
}
}