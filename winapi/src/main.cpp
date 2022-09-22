#include <Windows.h>
#include <string>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT messege, WPARAM wParam, LPARAM lParam)
{
    HWND file_path_text_box;
    switch (messege)
    {
    case WM_CREATE:
        file_path_text_box = CreateWindow(_T("EDIT"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 100, 400, 20, hWnd,
                                          NULL, NULL, NULL);
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
