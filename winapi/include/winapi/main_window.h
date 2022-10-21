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
    HWND button_output = NULL;
    HWND button_browse = NULL;
    HWND text_box = NULL;
    HWND static_text = NULL;
    LPWSTR file_name;
    OPENFILENAME open_file_name;
    WNDCLASS main_wndclass;
    bool set_open_file_name_params();
    bool setup_main_wndclass();
    bool create_main_window();
    bool create_button_output();
    bool create_button_browse();
    bool create_text_box();
    bool create_static_text();
    bool on_create(HWND parent);
    bool on_command(WPARAM wParam);
    bool on_size(const int width, const int height);
    bool move_text_box(const int width, const int height);
    bool move_static_text(const int width, const int height);
    bool move_button_output(const int width, const int height);
    bool move_button_browse(const int width, const int height);
    bool open_file_browse();

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  public:
    main_window();
    ~main_window();
    bool run(int nCmdShow);
};
}