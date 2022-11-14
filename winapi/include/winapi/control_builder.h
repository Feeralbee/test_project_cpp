#pragma once
#include "winapi/control.h"

#include <Windows.h>
#include <map>
#include <memory>
#include <string>

namespace winapi
{
class control_builder : public control
{
    std::unique_ptr<control> window;

  public:
    control_builder(std::wstring name);
    std::unique_ptr<control> get_control();
    void set_text(std::wstring);
    void set_style(int flags);
    void set_size_params(int width, int height, int x, int y);
    void set_parent_hwnd(HWND parent_hwnd);
    void set_ex_styles(int ex_styles);
    void set_hinstance(HINSTANCE hintance);
    void set_hmenu(HMENU hmenu);
    void set_lparam(LPVOID lparam);
};
}
