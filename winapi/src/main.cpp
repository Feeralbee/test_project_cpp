#include <Windows.h>
#include <string>
#include <tchar.h>

void paint(HWND &hWnd)
{
    HDC hdc;
    PAINTSTRUCT paint_struct;
    hdc = BeginPaint(hWnd, &paint_struct);
    HFONT font = CreateFont(25, 15, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                            CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_ROMAN, _T("main_font"));
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 255, 255));
    SelectObject(hdc, font);
    TextOut(hdc, 11, 70, _T("Input file path:"), 16);
}

void create_text_box_and_button(HWND &hWnd, HWND &text_box)
{
    CreateWindow(_T("BUTTON"), _T("Output"), WS_BORDER | WS_CHILD | WS_VISIBLE, 420, 100, 70, 20, hWnd, (HMENU)1, NULL,
                 NULL);
    text_box =
        CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 100, 400, 20, hWnd, NULL, NULL, NULL);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messege, WPARAM wParam, LPARAM lParam)
{
    HWND file_path_text_box;
    switch (messege)
    {
    case WM_PAINT:
        paint(hWnd);
        break;
    case WM_CREATE:
        create_text_box_and_button(hWnd, file_path_text_box);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return (DefWindowProc(hWnd, messege, wParam, lParam));
    }
    return 0;
}

TCHAR szProgName[] = _T("febe_test");

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS main_window;                              //������ ��������� ��������� WNDCLASS � �������� � ���������
    main_window.lpszClassName = szProgName;            //��� ���������
    main_window.hInstance = descriptor;                //������������� �������� ����������
    main_window.lpfnWndProc = WndProc;                 //��������� �� ������� ����
    main_window.hCursor = LoadCursor(NULL, IDC_ARROW); //��������� ������ � ���� �������
    main_window.hIcon = 0;                             //������ � ��� �� ����� ����
    main_window.lpszMenuName = 0;                      //� ���� ���� �� �����
    main_window.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //���� ���� ���� - �����
    main_window.style = CS_HREDRAW | CS_VREDRAW;                      //����� ���� - ���������������� �� � � �� �
    main_window.cbClsExtra = 0;
    main_window.cbWndExtra = 0;
    if (!RegisterClass(&main_window))
        return 0;
    hWnd = CreateWindow(szProgName,            //��� ���������
                        _T("febe_test"),       //��������� ����
                        WS_OVERLAPPEDWINDOW,   //����� ���� - ���������������
                        550,                   //��������� ���� �� ������ �� �
                        210,                   //�� �
                        800,                   //������� �� �
                        500,                   //�� �
                        (HWND)NULL,            //������������� ������������� ����
                        (HMENU)NULL,           //������������� ����
                        (HINSTANCE)descriptor, //������������� ���������� ���������
                        (HINSTANCE)NULL);      //���������� �������������� ����������
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return 0;
}
