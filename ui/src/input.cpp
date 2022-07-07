#include "ui/input.h"
#include "ui/std_out.h"

#include <filesystem>
#include <iostream>
#include <memory>
#include <utility>

namespace ui
{
namespace input
{
std::unique_ptr<std::filesystem::path> file_path()
{
    std::unique_ptr<std::filesystem::path> file_path = std::make_unique<std::filesystem::path>();
    platform::init_input();
    std::cin >> *file_path;
    return file_path;
}
}
}
