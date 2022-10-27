#pragma once
#include <Windows.h>
#include <string>
#include <tchar.h>

namespace winapi
{
class main_window
{
    enum class file_status
    {
        not_found,
        openned,
        extension_not_supported
    };

    enum class button
    {
        output,
        browse
    };

  private:
    const std::wstring window_class_name = _T("main_window");
    HWND window = NULL;
    HWND button_output = NULL;
    HWND button_browse = NULL;
    HWND text_box = NULL;
    HWND static_text = NULL;
    wchar_t file_path[260];
    WNDCLASS main_wndclass;
    file_status file_reading(std::wstring &content);
    bool setup_main_wndclass();
    bool create_main_window();
    bool create_button_output();
    bool create_button_browse();
    bool create_text_box();
    bool create_static_text();
    bool on_create(HWND parent);
    bool on_command(WPARAM wParam);
    bool on_size(const int width, const int height);
    bool on_button_output();
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