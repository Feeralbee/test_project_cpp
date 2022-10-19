#include "winapi/main_window.h"
#include "winapi/application.h"

namespace winapi
{
main_window::main_window()
{
    std::memset(&main_wndclass, 0, sizeof main_wndclass);
    if (setup_main_wndclass())
    {
        create_main_window();
    }
}

main_window::~main_window()
{
    if (window != NULL)
        DestroyWindow(window);
    if (button != NULL)
        DestroyWindow(button);
    if (text_box != NULL)
        DestroyWindow(text_box);
    if (static_text != NULL)
        DestroyWindow(static_text);
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
    break;
    case WM_SIZE: {
        auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        auto width = LOWORD(lParam);
        auto heigth = HIWORD(lParam);
        window_object->on_size(width, heigth);
        break;
    }
    case WM_CREATE: {
        auto create_struct = reinterpret_cast<CREATESTRUCT *>(lParam);
        auto window_object = reinterpret_cast<main_window *>(create_struct->lpCreateParams);
        window_object->on_create(hWnd);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window_object));
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

bool main_window::create_main_window()
{
    auto main_wnd = CreateWindow(window_class_name.c_str(), _T("febe_test"), WS_OVERLAPPEDWINDOW, 550, 210, 800, 500,
                                 NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), this);
    if (main_wnd != NULL)
        return 1;
    return 0;
}

bool main_window::create_button()
{
    button = CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 430, 175, 70, 20, window,
                          (HMENU)1, NULL, NULL);
    if (button != NULL)
        return 1;
    return 0;
}

bool main_window::create_static_text()
{
    static_text = CreateWindowEx(WS_EX_TRANSPARENT, _T("STATIC"), _T("Input file path:"), WS_VISIBLE | WS_CHILD, 100,
                                 130, 100, 18, window, NULL, NULL, NULL);
    if (static_text != NULL)
        return 1;
    return 0;
}

bool main_window::create_text_box()
{
    text_box = CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 100, 150, 400, 20, window, NULL,
                            NULL, NULL);
    if (text_box != NULL)
        return 1;
    return 0;
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

bool main_window::on_create(HWND parent)
{
    window = parent;
    if (window != NULL)
    {
        auto result = create_static_text();
        result |= create_button();
        result |= create_text_box();
        return result;
    }
    return 0;
}

bool main_window::on_size(int width, int heigth)
{
    width, heigth;
    return 0;
}
}
