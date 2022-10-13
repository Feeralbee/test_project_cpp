#pragma once
#include <Windows.h>
#include <string>
#include <tchar.h>

namespace winapi
{
class main_window
{
  private:
    HWND window;
    HWND button;
    HWND text_box;
    HWND static_text;
    WNDCLASS main_wndclass;
    bool setup_main_wndclass();

  public:
    main_window();
    ~main_window();
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
}