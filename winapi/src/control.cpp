#include "winapi/control.h"

#include <Windows.h>
#include <string>

namespace winapi
{
control::control(int x, int y, int width, int height, HMENU hmenu)
    : _x(x), _y(y), _width(width), _height(height), _hmenu(hmenu)
{
}

bool control::move()
{
    auto result = MoveWindow(_hwnd, _x, _y, _width, _height, TRUE);
    return result;
}

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

bool control::create(int ex_style, std::wstring class_name, std::wstring text, int style, HWND parent,
                     HINSTANCE hinstance, LPVOID lParam)
{
    _hwnd = CreateWindowEx(ex_style, class_name.c_str(), text.c_str(), style, _x, _y, _width, _height, parent, _hmenu,
                           hinstance, lParam);
    if (_hwnd != NULL)
        return true;
    return false;
}
}
