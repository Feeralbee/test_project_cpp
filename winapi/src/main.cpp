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
    WNDCLASS main_window;                              //создаём экземпляр структуры WNDCLASS и начинаем её заполнять
    main_window.lpszClassName = szProgName;            //имя программы
    main_window.hInstance = descriptor;                //идентификатор текущего приложения
    main_window.lpfnWndProc = WndProc;                 //указатель на функцию окна
    main_window.hCursor = LoadCursor(NULL, IDC_ARROW); //загружаем курсор в виде стрелки
    main_window.hIcon = 0;                             //иконки у нас не будет пока
    main_window.lpszMenuName = 0;                      //и меню пока не будет
    main_window.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //цвет фона окна - белый
    main_window.style = CS_HREDRAW | CS_VREDRAW;                      //стиль окна - перерисовываемое по х и по у
    main_window.cbClsExtra = 0;
    main_window.cbWndExtra = 0;
    if (!RegisterClass(&main_window))
        return 0;
    hWnd = CreateWindow(szProgName,            //Имя программы
                        _T("febe_test"),       //Заголовок окна
                        WS_OVERLAPPEDWINDOW,   //Стиль окна - перекрывающееся
                        550,                   //положение окна на экране по х
                        210,                   //по у
                        800,                   //размеры по х
                        500,                   //по у
                        (HWND)NULL,            //идентификатор родительского окна
                        (HMENU)NULL,           //идентификатор меню
                        (HINSTANCE)descriptor, //идентификатор экземпляра программы
                        (HINSTANCE)NULL);      //отсутствие дополнительных параметров
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return 0;
}
