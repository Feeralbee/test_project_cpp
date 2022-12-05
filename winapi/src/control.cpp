#include "winapi/control.h"

#include <Windows.h>
#include <string>
#include <tuple>

namespace winapi
{
bool control::destroy()
{
    if (_hwnd != NULL)
        return (DestroyWindow(_hwnd));
    return true;
}

HWND control::get_hwnd() const
{
    return _hwnd;
}

std::tuple<int, int> control::get_parent_size()
{
    auto parent = GetParent(_hwnd);
    RECT parent_rect;
    GetClientRect(parent, &parent_rect);

    const int width = parent_rect.right - parent_rect.left;
    const int height = parent_rect.bottom - parent_rect.top;

    return std::make_tuple(width, height);
}

bool control::move()
{
    auto [parent_width, parent_height] = get_parent_size();
    auto [x, y, width, heigth] = this->calculate_position(parent_width, parent_height);
    auto result = MoveWindow(_hwnd, x, y, width, heigth, TRUE);

    return result;
}

bool control::create(int ex_style, std::wstring class_name, std::wstring text, int style, int x, int y, int width,
                     int height, HWND parent, HMENU hmenu, HINSTANCE hinstance, LPVOID lParam)
{
    _hwnd = CreateWindowEx(ex_style, class_name.c_str(), text.c_str(), style, x, y, width, height, parent, hmenu,
                           hinstance, lParam);
    if (_hwnd != NULL)
        return true;
    return false;
}
bool control::set_window_text(std::wstring text)
{
    return SetWindowText(_hwnd, text.c_str());
}
}
