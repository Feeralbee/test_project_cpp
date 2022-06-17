#include "ui/input.h"
#include "ui/std_out.h"

#include <filesystem>
#include <iostream>

namespace ui
{
namespace input
{
std::filesystem::path file_path()
{
    std::filesystem::path file_path;
    platform::init_input();
    std::cin >> file_path;
    return file_path;
}
}
}
