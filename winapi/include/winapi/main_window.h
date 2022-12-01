#pragma once
#include "winapi/button_browse.h"
#include "winapi/combo_box.h"
#include "winapi/control.h"
#include "winapi/list_box.h"
#include "winapi/static_box.h"
#include "winapi/static_text.h"

#include <Windows.h>
#include <map>
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
    std::shared_ptr<button_browse> _button_browse;
    std::shared_ptr<combo_box> _path_box;
    std::shared_ptr<static_text> _static_text;
    std::shared_ptr<static_box> _static_box;
    std::shared_ptr<list_box> _list_box;
    WNDCLASS main_wndclass;
    std::map<HWND, std::shared_ptr<control>> controls_list;
    std::vector<std::wstring> boxes_data;
    file_status file_reading(const std::wstring file_path, std::wstring &content);
    bool setup_main_wndclass();
    bool on_create(HWND parent);
    bool on_command(WPARAM wParam, LPARAM lParam);
    bool on_size();
    bool open_file_browse();

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

  public:
    main_window();
    ~main_window();
    bool create();
    bool run(int nCmdShow);
};
}