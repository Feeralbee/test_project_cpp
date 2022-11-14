#include "winapi/control.h"

#include <Windows.h>
#include <string>

namespace winapi
{
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
bool control::create()
{
    _hwnd = CreateWindowEx(_ex_style, _class_name.c_str(), _text.c_str(), _style, _x, _y, _width, _height, _parent_hwnd,
                           _hmenu, _hinstance, _lparam);
    if (_hwnd != NULL)
        return true;
    return false;
}
}
