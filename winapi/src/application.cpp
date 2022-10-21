#include "winapi/application.h"
#include <memory>

namespace winapi
{
std::unique_ptr<application> application::get_application()
{
    return std::make_unique<application>();
}

std::unique_ptr<main_window> application::create_main_window() const
{
    return std::make_unique<main_window>();
}
}
