#include "winapi/list_box.h"
#include "winapi/control.h"

#include <tuple>

namespace winapi
{
std::tuple<int, int, int, int> list_box::calculate_position(int parent_width, int parent_height)
{
    const int width = parent_width / 2;
    const int height = parent_height / 2;

    const int x = 0;
    const int y = height / 5;
    return std::make_tuple(x, y, width, height);
}

}
