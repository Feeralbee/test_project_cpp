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

LRESULT list_box::set_item_data(WPARAM value, LPARAM index)
{
    return SendMessage(_hwnd, LB_SETITEMDATA, value, index);
}

LRESULT list_box::get_item_data(WPARAM index)
{
    return SendMessage(_hwnd, LB_GETITEMDATA, index, NULL);
}

LRESULT list_box::set_cursel(WPARAM index)
{
    return SendMessage(_hwnd, LB_SETCURSEL, index, NULL);
}

LRESULT list_box::get_cursel()
{
    return SendMessage(_hwnd, LB_GETCURSEL, NULL, NULL);
}

LRESULT list_box::insert_string(WPARAM index, LPARAM string)
{
    return SendMessage(_hwnd, LB_INSERTSTRING, index, string);
}
}
