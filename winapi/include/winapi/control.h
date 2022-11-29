#pragma once
#include <Windows.h>
#include <string>
#include <tuple>

namespace winapi
{

enum class button
{
    browse
};

class control
{
  protected:
    HWND _hwnd = NULL;
    std::tuple<int, int> get_parent_size();
    virtual std::tuple<int, int, int, int> calculate_position(int parent_width, int parent_height) = 0;

  public:
    control() = default;
    ~control() = default;
    HWND get_hwnd() const;
    bool move();
    bool destroy();
    bool create(int ex_style, std::wstring class_name, std::wstring text, int style, int x, int y, int width,
                int height, HWND parent, HMENU hmenu, HINSTANCE hinstance, LPVOID lParam);
};
}
