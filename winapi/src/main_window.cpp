#include "winapi/main_window.h"
#include "winapi/application.h"

namespace winapi
{
main_window::main_window()
{
    auto app = application::get_application();
    std::memset(&main_wndclass, 0, sizeof main_wndclass);
    if (setup_main_wndclass())
    {
        window = CreateWindow(app->get_program_name().c_str(), _T("febe_test"), WS_OVERLAPPEDWINDOW, 550, 210, 800, 500,
                              NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);
        if (window != NULL)
        {
            button = CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 100, 100, 70, 20,
                                  window, (HMENU)1, NULL, NULL);
            text_box = CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 100, 150, 400, 20, window,
                                    NULL, NULL, NULL);
        }
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
        DestroyWindow(button);
        DestroyWindow(text_box);
        DestroyWindow(static_text);
        GetClientRect(hWnd, &main_window_client_rect);
        create_static_text(hWnd);
        create_text_box(hWnd);
        create_button_output(hWnd);
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
    main_wndclass.lpszClassName = application::get_application->;
    main_wndclass.hInstance = (HINSTANCE)GetModuleHandle(NULL);
    main_wndclass.lpfnWndProc = WndProc;
    main_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    main_wndclass.hIcon = LoadIcon((HINSTANCE)GetModuleHandle(NULL), IDI_APPLICATION);
    main_wndclass.lpszMenuName = 0;
    main_wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    main_wndclass.style = CS_HREDRAW | CS_VREDRAW;
    main_wndclass.cbClsExtra = 0;
    main_wndclass.cbWndExtra = 0;
    if (!RegisterClass(&main_wndclass))
        return 0;
    return 1;
}

}
