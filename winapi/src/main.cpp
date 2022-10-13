#include "winapi/main_window.h"

#include <Windows.h>
#include <string>
#include <tchar.h>

RECT main_window_client_rect = {0, 0, 0, 0};

void create_static_text(HWND &main_window)
{
    int text_box_x = (main_window_client_rect.right / 2) - 325;
    int text_box_y = (main_window_client_rect.bottom / 2) - 39;
    static_text = CreateWindowEx(WS_EX_TRANSPARENT, _T("STATIC"), _T("Input file path:"), WS_VISIBLE | WS_CHILD,
                                 text_box_x, text_box_y, 100, 18, main_window, NULL, NULL, NULL);
}

void create_text_box(HWND &main_window)
{
    int text_box_x = (main_window_client_rect.right / 2) - 220;
    int text_box_y = (main_window_client_rect.bottom / 2) - 40;
}

void create_button_output(HWND &main_window)
{
    int button_x = (main_window_client_rect.right / 2) - 70;
    int button_y = (main_window_client_rect.bottom / 2) - 15;
    button = CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, button_x, button_y, 70, 20,
                          main_window, (HMENU)1, NULL, NULL);
}

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    if (hWnd != NULL)
    {
        ShowWindow(hWnd, nCmdShow);
        UpdateWindow(hWnd);
        MSG lpMsg;
        while (GetMessage(&lpMsg, NULL, 0, 0))
        {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    }
    return 0;
}
