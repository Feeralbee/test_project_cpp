#include "ui/input.h"

namespace ui
{
namespace input
{
std::filesystem::path file_path()
{
    std::filesystem::path file_path;
    std::cin >> file_path;
    return file_path;
}
}
}
