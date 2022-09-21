#include <Windows.h>
#include <string>

typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> String;

//������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;        //������ �������� ����������
    PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������
    static String str;
    //���� ��������� ���������
    switch (messg)
    {
        //��������� ���������
    case WM_CHAR:
        str += (TCHAR)wParam;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        //�������� ��������
        hdc = BeginPaint(hWnd, &ps);
        //����� �� ������ ���������� ���� �����:
        SetBkColor(hdc, RGB(255, 255, 0));
        auto font = CreateFont(20, 0, 0, 0, 400, NULL, NULL, NULL, DEFAULT_CHARSET, );
        SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
        TextOut(hdc, 250, 150, "������� ���� � �����: ", 22);
        TextOut(hdc, 250, 180, "                      ", 22);
        TextOut(hdc, 250, 180, str.data(), int(str.size()));
        //������������
        //��������� ����
        ValidateRect(hWnd, NULL);
        //����������� ��������
        EndPaint(hWnd, &ps);
        break;
        //��������� ������ - ���������� ����
    case WM_DESTROY:
        PostQuitMessage(0); //�������� ��������� ������ � ����� 0 - ���������� ����������
        break;
    default:
        return (DefWindowProc(hWnd, messg, wParam, lParam));
        //����������� ������� ���������� �� �������������
    }
    return 0;
}

//��������� ��� ���������
char szProgName[] = "febe_test";

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    HWND hWnd; //������������� ����
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
    //���� �� ������� ���������������� ����� ���� - �������
    if (!RegisterClass(&main_window))
        return 0;
    //�������� ���� � ������, �������� ��������� CreateWindow
    hWnd = CreateWindow(szProgName,            //��� ���������
                        "febe_test",           //��������� ����
                        WS_OVERLAPPEDWINDOW,   //����� ���� - ���������������
                        550,                   //��������� ���� �� ������ �� �
                        210,                   //�� �
                        800,                   //������� �� �
                        500,                   //�� �
                        (HWND)NULL,            //������������� ������������� ����
                        (HMENU)NULL,           //������������� ����
                        (HINSTANCE)descriptor, //������������� ���������� ���������
                        (HINSTANCE)NULL);      //���������� �������������� ����������
    //������� ���� �� ������ �� �����
    ShowWindow(hWnd, nCmdShow);
    //������� ���������� ����
    UpdateWindow(hWnd);
    //���� ��������� ���������
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {                             //�������� ��������� �� �������
        TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
        DispatchMessage(&lpMsg);  //������� ��������� ��������������� ������� ����
    }
    return 0;
}
