#include <Windows.h>
#include <string>
#include <tchar.h>

TCHAR szProgName[] = _T("febe_test");

void paint(HWND &hWnd)
{
    HDC hdc = NULL;
    PAINTSTRUCT paint_struct;
    hdc = BeginPaint(hWnd, &paint_struct);
    if (hdc != NULL)
    {
        HFONT font = CreateFont(25, 15, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                                CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_ROMAN, _T("main_font"));
        if (font != NULL)
        {
            if (SetBkMode(hdc, TRANSPARENT))
            {
                SetTextColor(hdc, RGB(255, 255, 255));
                SelectObject(hdc, font);
                TextOut(hdc, 11, 70, _T("Input file path:"), 16);
            }
            else
            {
                MessageBox(hWnd, _T("SetBkMode function return NULL"), _T("Background color error"), MB_ICONERROR);
            }
        }
        else
        {
            MessageBox(hWnd, _T("CreateFont function return NULL"), _T("CreateFont error"), MB_ICONERROR);
        }
    }
    else
    {
        MessageBox(hWnd, _T("BeginPaint function return NULL"), _T("BeginPaint error"), MB_ICONERROR);
    }
}

int create_text_box_and_button(HWND &hWnd, HWND &text_box)
{
    CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 100, 70, 20, hWnd, (HMENU)1, NULL,
                 NULL);
    text_box =
        CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 100, 400, 20, hWnd, NULL, NULL, NULL);
    if (text_box != NULL)
        return 1;
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messege, WPARAM wParam, LPARAM lParam)
{
    HWND file_path_text_box;
    LPWSTR file_path{};
    switch (messege)
    {
    case WM_PAINT:
        paint(hWnd);
        break;
    case WM_CREATE:
        if (create_text_box_and_button(hWnd, file_path_text_box) == 1)
            GetWindowText(file_path_text_box, file_path, GetWindowTextLength(file_path_text_box));
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return (DefWindowProc(hWnd, messege, wParam, lParam));
    }
    return 0;
}

void setup_main_window(HINSTANCE &descriptor, WNDCLASS &main_window)
{
    main_window.lpszClassName = szProgName;
    main_window.hInstance = descriptor;
    main_window.lpfnWndProc = WndProc;
    main_window.hCursor = LoadCursor(NULL, IDC_ARROW);
    main_window.hIcon = 0;
    main_window.lpszMenuName = 0;
    main_window.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    main_window.style = CS_HREDRAW | CS_VREDRAW;
    main_window.cbClsExtra = 0;
    main_window.cbWndExtra = 0;
}

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASS main_window;
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
