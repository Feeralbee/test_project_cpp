#pragma once
#include <Windows.h>
#include <string>

namespace winapi
{
class control
{
  protected:
    HWND _hwnd = NULL;
    int _x;
    int _y;
    int _width;
    int _height;
    HMENU _hmenu;

  public:
    control(int x, int y, int width, int height, HMENU hmenu);
    ~control() = default;
    bool move();
    bool destroy();
    bool create(int ex_style, std::wstring class_name, std::wstring text, int style, HWND parent, HINSTANCE hinstance,
                LPVOID lParam);
};
}
