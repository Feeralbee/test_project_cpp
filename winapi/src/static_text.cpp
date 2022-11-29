#include "winapi/static_text.h"
#include "winapi/control.h"

#include <tuple>

namespace winapi
{
std::tuple<int, int, int, int> static_text::calculate_position(int parent_width, int parent_height)
{
    const int width = 100;
    const int height = width / 5;

    const int x = (parent_width / 2 - parent_width / 4) - width;
    const int y = parent_height - height * 2;
    return std::make_tuple(x, y, width, height);
}

}
