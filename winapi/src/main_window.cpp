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
        // GetClientRect(hWnd, &main_window_client_rect);
        break;
    }
    case WM_CREATE: {
        auto create_struct = reinterpret_cast<CREATESTRUCT *>(lParam);
        auto window_object = reinterpret_cast<main_window *>(create_struct->lpCreateParams);
        window_object->on_create();
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
    window = CreateWindow(window_class_name.c_str(), _T("febe_test"), WS_OVERLAPPEDWINDOW, 550, 210, 800, 500, NULL,
                          NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);
    if (window != NULL)
        return 1;
    return 0;
}
bool main_window::create_button()
{
    if (window != NULL)
    {
        button = CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 100, 100, 70, 20, window,
                              (HMENU)1, NULL, NULL);
    }
    if (button != NULL)
        return 1;
    return 0;
}
bool main_window::create_static_text()
{
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
bool main_window::on_create()
{
    create_static_text();
    create_button();
    // create_text_box();
    return GetLastError();
}
}
