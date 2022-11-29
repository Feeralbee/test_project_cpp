#include "winapi/combo_box.h"
#include "winapi/control.h"

#include <tuple>

namespace winapi
{
std::tuple<int, int, int, int> combo_box::calculate_position(int parent_width, int parent_height)
{
    const int height = 20;
    const int width = parent_width / 2;

    const int x = (parent_width / 2) - (width / 2);
    const int y = parent_height - height * 2;
    return std::make_tuple(x, y, width, height);
}
}
