#pragma once
#include <Windows.h>
#include <string>

namespace winapi
{
class control
{
  protected:
    int _style = 0;
    std::wstring _text = NULL;
    std::wstring _class_name = NULL;
    HMENU _hmenu = NULL;
    HWND _parent_hwnd = NULL;
    HINSTANCE _hinstance = NULL;
    LPVOID _lparam = NULL;
    int _ex_style = 0;
    int _width = 0;
    int _height = 0;
    int _x = 0;
    int _y = 0;
    int _screen_width;
    int _screen_height;
    HWND _hwnd = NULL;
    // virtual bool check_important_params();
  public:
    control() = default;
    ~control() = default;
    bool move();
    bool destroy();
    bool create();
    virtual bool on_command() = 0;
};
}
