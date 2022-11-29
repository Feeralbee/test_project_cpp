#include "winapi/static_box.h"
#include "winapi/control.h"

namespace winapi
{
std::tuple<int, int, int, int> static_box::calculate_position(int parent_width, int parent_height)
{
    const int width = parent_width / 2;
    const int height = parent_height - parent_height / 10;

    const int x = width / 2;
    const int y = 0;

    return std::make_tuple(x, y, width, height);
}
}