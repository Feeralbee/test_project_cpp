#include <Windows.h>
#include <string>
#include <tchar.h>

TCHAR szProgName[] = _T("febe_test");

int create_text_box_and_button(HWND &hWnd, HWND &text_box)
{
    auto static_text =
        CreateWindowEx(WS_EX_TRANSPARENT | WS_EX_LAYERED | WS_EX_TOOLWINDOW, _T("STATIC"), _T("Input file path"),
                       WS_BORDER | WS_CHILD | WS_VISIBLE, 11, 70, 95, 20, hWnd, NULL, NULL, NULL);
    static_text;

    CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 100, 70, 20, hWnd, (HMENU)1, NULL,
                 NULL);
    text_box =
        CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 100, 400, 20, hWnd, NULL, NULL, NULL);
    if (text_box != NULL)
        return 1;
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT: {

        break;
    }
    case WM_CREATE: {
        HWND file_path_text_box;
        LPWSTR file_path{};
        if (create_text_box_and_button(hWnd, file_path_text_box) == 1)
            GetWindowText(file_path_text_box, file_path, GetWindowTextLength(file_path_text_box));
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
    HWND hWnd = CreateWindow(szProgName, _T("febe_test"), WS_OVERLAPPEDWINDOW, 550, 210, 800, 500, (HWND)NULL,
                             (HMENU)NULL, (HINSTANCE)descriptor, (HINSTANCE)NULL);
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
