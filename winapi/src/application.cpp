#include "winapi/application.h"
#include <memory>

namespace winapi
{
std::unique_ptr<application> application::get_application()
{
    return std::make_unique<application>(application());
}
std::wstring application::get_program_name()
{
    return programm_name;
}
}
