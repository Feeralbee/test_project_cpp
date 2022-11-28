#pragma once
#include "winapi/control.h"

#include <Windows.h>
#include <memory>
#include <string>
#include <tchar.h>
#include <vector>

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

  private:
    const std::wstring window_class_name = _T("main_window");
    HWND window = NULL;
    std::unique_ptr<control> button_browse;
    std::unique_ptr<control> path_box;
    std::unique_ptr<control> static_text;
    std::unique_ptr<control> static_box;
    std::unique_ptr<control> list_box;
    WNDCLASS main_wndclass;
    std::vector<std::wstring> boxes_data;
    file_status file_reading(const std::wstring file_path, std::wstring &content);
    bool setup_main_wndclass();
    bool create_button_browse();
    bool create_path_box();
    bool create_static_text();
    bool create_static_box();
    bool create_list_box();
    bool on_create(HWND parent);
    bool on_command(WPARAM wParam, LPARAM lParam);
    bool on_size(const int width, const int height);
    bool move_path_box(const int width, const int height);
    bool move_list_box(const int width, const int height);
    bool move_static_text(const int width, const int height);
    bool move_static_box(const int width, const int height);
    bool move_button_browse(const int width, const int height);
    bool open_file_browse();

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  public:
    main_window();
    ~main_window();
    bool create();
    bool run(int nCmdShow);
};
}