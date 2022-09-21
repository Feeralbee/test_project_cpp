#include <Windows.h>
#include <string>

typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> String;

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;        //создаём контекст устройства
    PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
    static String str;
    //Цикл обработки сообщений
    switch (messg)
    {
        //сообщение рисования
    case WM_CHAR:
        str += (TCHAR)wParam;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        //начинаем рисовать
        hdc = BeginPaint(hWnd, &ps);
        //здесь вы обычно вставляете свой текст:
        SetBkColor(hdc, RGB(255, 255, 0));
        auto font = CreateFont(20, 0, 0, 0, 400, NULL, NULL, NULL, DEFAULT_CHARSET, );
        SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
        TextOut(hdc, 250, 150, "Введите путь к файлу: ", 22);
        TextOut(hdc, 250, 180, "                      ", 22);
        TextOut(hdc, 250, 180, str.data(), int(str.size()));
        //закругляемся
        //обновляем окно
        ValidateRect(hWnd, NULL);
        //заканчиваем рисовать
        EndPaint(hWnd, &ps);
        break;
        //сообщение выхода - разрушение окна
    case WM_DESTROY:
        PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
        break;
    default:
        return (DefWindowProc(hWnd, messg, wParam, lParam));
        //освобождаем очередь приложения от нераспознаных
    }
    return 0;
}

//объявляем имя программы
char szProgName[] = "febe_test";

int WINAPI WinMain(HINSTANCE descriptor, HINSTANCE, LPSTR, int nCmdShow)
{
    HWND hWnd; //идентификатор окна
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
    //Если не удалось зарегистрировать класс окна - выходим
    if (!RegisterClass(&main_window))
        return 0;
    //Создадим окно в памяти, заполнив аргументы CreateWindow
    hWnd = CreateWindow(szProgName,            //Имя программы
                        "febe_test",           //Заголовок окна
                        WS_OVERLAPPEDWINDOW,   //Стиль окна - перекрывающееся
                        550,                   //положение окна на экране по х
                        210,                   //по у
                        800,                   //размеры по х
                        500,                   //по у
                        (HWND)NULL,            //идентификатор родительского окна
                        (HMENU)NULL,           //идентификатор меню
                        (HINSTANCE)descriptor, //идентификатор экземпляра программы
                        (HINSTANCE)NULL);      //отсутствие дополнительных параметров
    //Выводим окно из памяти на экран
    ShowWindow(hWnd, nCmdShow);
    //Обновим содержимое окна
    UpdateWindow(hWnd);
    //Цикл обработки сообщений
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {                             //Получаем сообщение из очереди
        TranslateMessage(&lpMsg); //Преобразуем сообщения клавиш в символы
        DispatchMessage(&lpMsg);  //Передаём сообщение соответствующей функции окна
    }
    return 0;
}
