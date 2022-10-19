#pragma once
#include <Windows.h>
#include <string>
#include <tchar.h>

namespace winapi
{
class main_window
{
  private:
    const std::wstring window_class_name = _T("main_window");
    HWND window = NULL;
    HWND button = NULL;
    HWND text_box = NULL;
    HWND static_text = NULL;
    WNDCLASS main_wndclass;
    bool setup_main_wndclass();
    bool create_main_window();
    bool create_button();
    bool create_text_box();
    bool create_static_text();
    bool on_create(HWND parent);
    bool on_size(int width, int heigth);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  public:
    main_window();
    ~main_window();
    bool run(int nCmdShow);
};
}