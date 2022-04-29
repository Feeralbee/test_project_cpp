#include "ui/input.h"

namespace ui
{
namespace input
{
std::string file_path()
{
    std::string FilePath;
    std::cin >> FilePath;
    return FilePath;
}

std::string user_choice()
{
    std::string choice;
    std::cin >> choice;
    return choice;
}
}
}
