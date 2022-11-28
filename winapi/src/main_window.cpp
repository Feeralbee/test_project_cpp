#include "winapi/main_window.h"
#include "readers/data.h"
#include "readers/factory.h"
#include "winapi/button_browse.h"
#include "winapi/control.h"
#include "winapi/control_box.h"
#include "winapi/list_box.h"
#include "winapi/static_control.h"

#include <CommCtrl.h>
#include <memory>
#include <string>
#include <vector>

namespace winapi
{
main_window::main_window()
{
    setup_main_wndclass();
    list_box = std::make_unique<winapi::list_box>()
}

main_window::~main_window()
{
    if (window != NULL)
        DestroyWindow(window);

    button_browse->destroy();
    list_box->destroy();
    path_box->destroy();
    static_box->destroy();
    static_text->destroy();
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
        const auto width = LOWORD(lParam);
        const auto height = HIWORD(lParam);
        window_object->on_size(width, height);
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
    default:
        return (DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0;
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
        list_box->create(NULL, L"LISTBOX", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY, window,
                         NULL, NULL);
        path_box->create();
        static_box->create();
        static_text->create();
        button_browse->create();
    }
    return 0;
}

bool main_window::create_list_box()
{
    const auto class_name = _T("LISTBOX");
    const auto text_in_window = _T("");
    const auto flags = WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOTIFY;

    list_box = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, window, NULL,
                            NULL, NULL);
    if (list_box != NULL)
        return 1;
    return 0;
}

bool main_window::create_button_browse()
{
    const auto class_name = _T("BUTTON");
    const auto text_in_window = _T("Browse");
    const auto flags = WS_CHILD | WS_VISIBLE | BS_FLAT | BS_VCENTER | BS_PUSHBUTTON;

    button_browse = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100, 22, window,
                                 (HMENU)button::browse, NULL, NULL);
    if (button_browse != NULL)
        return 1;
    return 0;
}

bool main_window::create_static_text()
{
    const auto class_name = _T("STATIC");
    const auto text_in_window = _T("Input file path:");
    const auto flags = WS_VISIBLE | WS_CHILD;

    static_text = CreateWindowEx(WS_EX_TRANSPARENT, class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT,
                                 100, 25, window, NULL, NULL, NULL);

    if (static_text != NULL)
        return 1;
    return 0;
}

bool main_window::create_static_box()
{
    const auto class_name = _T("STATIC");
    const auto text_in_window = _T("");
    const auto flags = WS_VISIBLE | WS_CHILD | WS_BORDER;

    static_box = CreateWindowEx(WS_EX_TRANSPARENT, class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100,
                                25, window, NULL, NULL, NULL);

    if (static_box != NULL)
        return 1;
    return 0;
}

bool main_window::create_path_box()
{
    const auto class_name = WC_COMBOBOX;
    const auto text_in_window = NULL;
    const auto flags = CBS_DROPDOWNLIST | CBS_AUTOHSCROLL | WS_TABSTOP | WS_VSCROLL | WS_VISIBLE | WS_CHILD;

    path_box = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100, 80, window, NULL,
                            NULL, NULL);

    if (path_box != NULL)
        return 1;
    return 0;
}

bool main_window::on_size(const int width, const int height)
{
    auto result = move_path_box(width, height);
    result |= move_button_browse(width, height);
    result |= move_static_text(width, height);
    result |= move_static_box(width, height);
    result |= move_list_box(width, height);
    return result;
}

bool main_window::move_button_browse(const int width, const int height)
{
    const int button_height = 20;
    const int button_width = 100;

    const int button_x = (width / 2 + width / 4) + button_width / 50;
    const int button_y = height - button_height * 2;

    const auto result = MoveWindow(button_browse, button_x, button_y, button_width, button_height, TRUE);

    return result;
}

bool main_window::move_list_box(const int width, const int height)
{
    const int box_width = width / 2;
    const int box_height = height / 2;

    const int box_x = 0;
    const int box_y = height / 5;

    const auto result = MoveWindow(list_box, box_x, box_y, box_width, box_height, TRUE);
    return result;
}

bool main_window::move_path_box(const int width, const int height)
{
    const int text_box_height = 20;
    const int text_box_width = width / 2;

    const int text_box_x = (width / 2) - (text_box_width / 2);
    const int text_box_y = height - text_box_height * 2;

    const auto result = MoveWindow(path_box, text_box_x, text_box_y, text_box_width, text_box_height, TRUE);

    return result;
}

bool main_window::move_static_text(const int width, const int height)
{
    const int static_text_width = 100;
    const int static_text_height = static_text_width / 5;

    const int static_text_x = (width / 2 - width / 4) - static_text_width;
    const int static_text_y = height - static_text_height * 2;

    const auto result =
        MoveWindow(static_text, static_text_x, static_text_y, static_text_width, static_text_height, TRUE);

    return result;
}

bool main_window::move_static_box(const int width, const int height)
{
    const int static_box_width = width / 2;
    const int static_box_height = height - height / 10;

    const int static_box_x = width / 2;
    const int static_box_y = 0;

    const auto result = MoveWindow(static_box, static_box_x, static_box_y, static_box_width, static_box_height, TRUE);

    return result;
}

bool main_window::on_command(WPARAM wParam, LPARAM lParam)
{
    if ((HWND)lParam == button_browse && (button)wParam == button::browse)
    {
        open_file_browse();
    }
    else if ((HWND)lParam == path_box)
    {
        if (HIWORD(wParam) == CBN_SELCHANGE)
        {
            auto item_index = SendMessage(path_box, CB_GETCURSEL, NULL, NULL);
            if (item_index != CB_ERR)
            {
                auto index = SendMessage(path_box, CB_GETITEMDATA, (WPARAM)item_index, NULL);
                SetWindowText(static_box, (LPWSTR)boxes_data.at(index).c_str());
                SendMessage(list_box, LB_SETCURSEL, (WPARAM)item_index, NULL);
            }
        }
    }
    else if ((HWND)lParam == list_box)
    {
        if (HIWORD(wParam) == LBN_SELCHANGE)
        {
            auto item_index = SendMessage(list_box, LB_GETCURSEL, NULL, NULL);
            if (item_index != LB_ERR)
            {
                auto index = SendMessage(list_box, LB_GETITEMDATA, (WPARAM)item_index, NULL);
                SetWindowText(static_box, (LPWSTR)boxes_data.at(index).c_str());
                SendMessage(path_box, CB_SETCURSEL, (WPARAM)item_index, NULL);
            }
        }
    }
    return 0;
}
/*
bool main_window::on_button_output()
{
    WCHAR path[MAX_PATH];
    std::memset(path, 0, sizeof(path));
    GetWindowText(path_box, path, MAX_PATH);

    return 1;
}
*/
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

bool main_window::open_file_browse()
{
    std::wstring content;
    auto reading_result = file_reading(path, content);
    if (reading_result == file_status::openned)
    {
        auto index = SendMessage(path_box, CB_FINDSTRING, (WPARAM)-1, (LPARAM)path);
        if (index == CB_ERR)
        {
            index = SendMessage(path_box, CB_ADDSTRING, NULL, (LPARAM)path);
            SendMessage(list_box, LB_INSERTSTRING, (WPARAM)index, (LPARAM)path);
            boxes_data.push_back(content);
            SendMessage(path_box, CB_SETITEMDATA, (WPARAM)index, (LPARAM)boxes_data.size() - 1);
            SendMessage(list_box, LB_SETITEMDATA, (WPARAM)index, (LPARAM)boxes_data.size() - 1);
        }
        SendMessage(path_box, CB_SETCURSEL, (WPARAM)index, NULL);
        SendMessage(list_box, LB_SETCURSEL, (WPARAM)index, NULL);
        SetWindowText(static_box, content.c_str());
    }
    else if (reading_result == file_status::extension_not_supported)
        MessageBox(window, L"File extension is not supported", L"Error", MB_OK | MB_ICONHAND);

    else if (reading_result == file_status::not_found)
        MessageBox(window, L"File is not found", L"Error", MB_OK | MB_ICONHAND);

    return 1;
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
