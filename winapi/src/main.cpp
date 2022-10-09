#include <Windows.h>
#include <string>
#include <tchar.h>

TCHAR szProgName[] = _T("febe_test");

HWND button;
HWND text_box;
HWND static_text;
RECT main_window_client_rect = {0, 0, 0, 0};

void create_static_text(HWND &main_window)
{
    int text_box_x = (main_window_client_rect.right / 2) - 325;
    int text_box_y = (main_window_client_rect.bottom / 2) - 39;
    static_text = CreateWindowEx(WS_EX_TRANSPARENT, _T("STATIC"), _T("Input file path:"), WS_VISIBLE | WS_CHILD,
                                 text_box_x, text_box_y, 100, 18, main_window, NULL, NULL, NULL);
    SetClassLongPtr(static_text, GCLP_HBRBACKGROUND, TRANSPARENT);
}

void create_text_box(HWND &main_window, LPWSTR &file_path)
{
    int text_box_x = (main_window_client_rect.right / 2) - 220;
    int text_box_y = (main_window_client_rect.bottom / 2) - 40;
    text_box = CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, text_box_x, text_box_y, 400, 20,
                            main_window, NULL, NULL, NULL);
    file_path;
}

void create_button_output(HWND &main_window)
{
    int button_x = (main_window_client_rect.right / 2) - 70;
    int button_y = (main_window_client_rect.bottom / 2) - 15;
    button = CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, button_x, button_y, 70, 20,
                          main_window, (HMENU)1, NULL, NULL);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    LPWSTR file_path{};
    switch (message)
    {
    case WM_SIZE: {
        DestroyWindow(button);
        DestroyWindow(text_box);
        DestroyWindow(static_text);
        GetClientRect(hWnd, &main_window_client_rect);
        create_static_text(hWnd);
        create_text_box(hWnd, file_path);
        create_button_output(hWnd);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return (DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0;
}

void setup_main_window(HINSTANCE &descriptor, WNDCLASS &main_window)
{
    main_window.lpszClassName = szProgName;
    main_window.hInstance = descriptor;
    main_window.lpfnWndProc = WndProc;
    main_window.hCursor = LoadCursor(NULL, IDC_ARROW);
    main_window.hIcon = LoadIcon(descriptor, IDI_APPLICATION);
    main_window.lpszMenuName = 0;
    main_window.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    main_window.style = CS_HREDRAW | CS_VREDRAW;
    main_window.cbClsExtra = 0;
    main_window.cbWndExtra = 0;
}

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASS main_window;
    std::memset(&main_window, 0, sizeof main_window);
    setup_main_window(descriptor, main_window);
    if (!RegisterClass(&main_window))
        return 0;
    HWND hWnd = CreateWindow(szProgName, _T("febe_test"), WS_OVERLAPPEDWINDOW, 550, 210, 800, 500, NULL, NULL,
                             descriptor, NULL);
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
