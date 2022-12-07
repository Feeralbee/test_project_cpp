#include "winapi/list_box.h"
#include "winapi/control.h"
#include "winapi/messages.h"

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

bool list_box::on_command(WPARAM wparam)
{
    if (wparam == LBN_SELCHANGE)
    {
        auto item_index = get_cursel();
        if (item_index != CB_ERR)
        {
            auto data = get_item_data((WPARAM)item_index);
            SendMessage(_hwnd, messages::LIST_BOX_CURSEL_CHANGED, (WPARAM)item_index, (LPARAM)data);
        }
        return 1;
    }
    return 0;
}
}
