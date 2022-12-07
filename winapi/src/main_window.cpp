#include "winapi/main_window.h"
#include "readers/data.h"
#include "readers/factory.h"
#include "winapi/button_browse.h"
#include "winapi/combo_box.h"
#include "winapi/control.h"
#include "winapi/list_box.h"
#include "winapi/messages.h"
#include "winapi/static_box.h"
#include "winapi/static_text.h"

#include <CommCtrl.h>
#include <memory>
#include <string>
#include <vector>

namespace winapi
{
main_window::main_window()
{
    setup_main_wndclass();
    _list_box = std::make_shared<list_box>();
    controls_list[_list_box->get_hwnd()] = _list_box;
    _button_browse = std::make_shared<button_browse>();
    controls_list[_button_browse->get_hwnd()] = _button_browse;
    _path_box = std::make_shared<combo_box>();
    controls_list[_path_box->get_hwnd()] = _path_box;
    _static_box = std::make_shared<static_box>();
    controls_list[_static_box->get_hwnd()] = _static_box;
    _static_text = std::make_shared<static_text>();
    controls_list[_static_text->get_hwnd()] = _static_text;
}

main_window::~main_window()
{
    if (window != NULL)
        DestroyWindow(window);
    for (auto &[hwnd, ctrl] : controls_list)
    {
        ctrl->destroy();
    }
}

LRESULT CALLBACK main_window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CTLCOLORSTATIC: {
        SetTextColor((HDC)wParam, RGB(255, 255, 255));
        SetBkMode((HDC)wParam, TRANSPARENT);
        return GetClassLongPtr(hWnd, GCLP_HBRBACKGROUND);
    }
    case WM_SIZE: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_size();
        break;
    }
    case WM_CREATE: {
        const auto create_struct = reinterpret_cast<CREATESTRUCT *>(lParam);
        const auto window_object = reinterpret_cast<main_window *>(create_struct->lpCreateParams);
        window_object->on_create(hWnd);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window_object));
        break;
    }
    case WM_GETMINMAXINFO: {
        LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
        lpMMI->ptMinTrackSize.x = GetSystemMetrics(SM_CXSCREEN) / 2;
        lpMMI->ptMinTrackSize.y = GetSystemMetrics(SM_CYSCREEN) / 2;
        break;
    }
    case WM_COMMAND: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_command(wParam, lParam);
        break;
    }
    case WM_DESTROY:
        DeleteObject((HBRUSH)GetClassLongPtr(hWnd, GCLP_HBRBACKGROUND));
        PostQuitMessage(0);
        break;
    case messages::FILE_PATH_WAS_INIT: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_file_path_was_init(wParam);
        break;
    }
    case messages::COMBO_BOX_CURSEL_CHANGED: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_combo_box_changed(wParam, lParam);
        break;
    }
    case messages::LIST_BOX_CURSEL_CHANGED: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_list_box_changed(wParam, lParam);
        break;
    }
    default:
        return (DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0;
}

bool main_window::on_file_path_was_init(WPARAM wparam)
{
    std::wstring content;
    std::wstring path = (LPWSTR)wparam;
    auto reading_result = file_reading(path, content);
    if (reading_result == file_status::openned)
    {
        auto index = _path_box->find_string((LPARAM)path.c_str());
        if (index == CB_ERR)
        {
            index = _path_box->add_string((LPARAM)path.c_str());
            _list_box->insert_string((WPARAM)index, (LPARAM)path.c_str());
            boxes_data.push_back(content);
            _path_box->set_item_data((WPARAM)index, (LPARAM)boxes_data.size() - 1);
            _list_box->set_item_data((WPARAM)index, (LPARAM)boxes_data.size() - 1);
        }
        _path_box->set_cursel((WPARAM)index);
        _list_box->set_cursel((WPARAM)index);
        _static_box->set_window_text(content);
    }
    else if (reading_result == file_status::extension_not_supported)
        MessageBox(window, L"File extension is not supported", L"Error", MB_OK | MB_ICONHAND);

    else if (reading_result == file_status::not_found)
        MessageBox(window, L"File is not found", L"Error", MB_OK | MB_ICONHAND);

    return 1;
}

bool main_window::on_combo_box_changed(WPARAM wparam, LPARAM lparam)
{
    _static_box->set_window_text(boxes_data.at(lparam));
    _list_box->set_cursel(wparam);
    return 1;
}

bool main_window::on_list_box_changed(WPARAM wparam, LPARAM lparam)
{
    _static_box->set_window_text(boxes_data.at(lparam));
    _path_box->set_cursel(wparam);
    return 1;
}

bool main_window::setup_main_wndclass()
{
    std::memset(&main_wndclass, 0, sizeof main_wndclass);
    main_wndclass.lpszClassName = window_class_name.c_str();
    main_wndclass.hInstance = (HINSTANCE)GetModuleHandle(NULL);
    main_wndclass.lpfnWndProc = WndProc;
    main_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    main_wndclass.hIcon = LoadIcon((HINSTANCE)GetModuleHandle(NULL), IDI_APPLICATION);
    main_wndclass.lpszMenuName = 0;
    main_wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    main_wndclass.style = CS_HREDRAW | CS_VREDRAW;
    main_wndclass.cbClsExtra = (int)GetClassLongPtr(window, GWLP_USERDATA);
    main_wndclass.cbWndExtra = 0;
    if (!RegisterClass(&main_wndclass))
        return 0;
    return 1;
}

bool main_window::create()
{
    const int screen_width = GetSystemMetrics(SM_CXSCREEN);
    const int screen_height = GetSystemMetrics(SM_CYSCREEN);

    RECT window_rect;
    window_rect.left = 0;
    window_rect.top = 0;
    window_rect.right = screen_width / 2;
    window_rect.bottom = screen_height / 2;

    AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW, NULL);
    const int window_height = window_rect.bottom - window_rect.top;
    const int window_width = window_rect.right - window_rect.left;

    const int window_x = (screen_width / 2) - (window_width / 2);
    const int window_y = (screen_height / 2) - (window_height / 2);

    const auto window_header = _T("febe_test");
    const auto flags = WS_OVERLAPPEDWINDOW;

    auto main_wnd = CreateWindow(window_class_name.c_str(), window_header, flags, window_x, window_y, window_width,
                                 window_height, NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), this);
    if (main_wnd != NULL)
        return 1;
    return 0;
}

bool main_window::on_create(HWND parent)
{
    window = parent;
    if (window != NULL)
    {
        _list_box->create(NULL, L"LISTBOX", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY,
                          CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, window, NULL, NULL, NULL);
        _button_browse->create(NULL, L"BUTTON", L"Browse", WS_CHILD | WS_VISIBLE | BS_FLAT | BS_VCENTER | BS_PUSHBUTTON,
                               CW_USEDEFAULT, CW_USEDEFAULT, 100, 22, window, (HMENU)button::browse, NULL, NULL);
        _static_box->create(NULL, L"STATIC", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, CW_USEDEFAULT, CW_USEDEFAULT, 100,
                            25, window, NULL, NULL, NULL);
        _static_text->create(NULL, L"STATIC", L"Input file path:", WS_VISIBLE | WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT,
                             100, 25, window, NULL, NULL, NULL);
        _path_box->create(NULL, L"COMBOBOX", L"",
                          CBS_DROPDOWNLIST | CBS_AUTOHSCROLL | WS_TABSTOP | WS_VSCROLL | WS_VISIBLE | WS_CHILD,
                          CW_USEDEFAULT, CW_USEDEFAULT, 100, 80, window, NULL, NULL, NULL);
    }
    return 0;
}

bool main_window::on_size()
{
    for (auto &[hwnd, ctrl] : controls_list)
    {
        ctrl->move();
    }
    return 1;
}

bool main_window::on_command(WPARAM wParam, LPARAM lParam)
{
    controls_list[(HWND)lParam]->on_command(wParam);
    return 0;
}

main_window::file_status main_window::file_reading(const std::wstring file_path, std::wstring &content)
{
    auto reader = readers::factory::create(file_path);
    if (reader != nullptr)
    {
        auto text = reader->get_content_from_file();
        if (text != nullptr)
        {
            for (auto i = 0; i < text->size(); i++)
            {
                content += text->at(i) + L"\n";
            }
            return file_status::openned;
        }
        return file_status::not_found;
    }
    return file_status::extension_not_supported;
}

bool main_window::run(int nCmdShow)
{
    if (window != NULL)
    {
        ShowWindow(window, nCmdShow);
        UpdateWindow(window);
        MSG lpMsg;
        while (GetMessage(&lpMsg, NULL, 0, 0))
        {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    }
    return GetLastError();
}
}
