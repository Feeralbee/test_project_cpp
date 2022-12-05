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

LRESULT combo_box::set_item_data(WPARAM value, LPARAM index)
{
    return SendMessage(_hwnd, CB_SETITEMDATA, value, index);
}

LRESULT combo_box::get_item_data(WPARAM index)
{
    return SendMessage(_hwnd, CB_GETITEMDATA, index, NULL);
}

LRESULT combo_box::set_cursel(WPARAM index)
{
    return SendMessage(_hwnd, CB_SETCURSEL, index, NULL);
}

LRESULT combo_box::get_cursel()
{
    return SendMessage(_hwnd, CB_GETCURSEL, NULL, NULL);
}

LRESULT combo_box::find_string(LPARAM string)
{
    return SendMessage(_hwnd, CB_FINDSTRING, (WPARAM)-1, string);
}

LRESULT combo_box::add_string(LPARAM string)
{
    return SendMessage(_hwnd, CB_ADDSTRING, NULL, string);
}

bool combo_box::on_command(WPARAM wparam)
{
    if (wparam == CBN_SELCHANGE)
    {
        return 1;
    }
    return 0;
}
}
