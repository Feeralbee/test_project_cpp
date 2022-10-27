#include "winapi/main_window.h"
#include "readers/data.h"
#include "readers/factory.h"
#include <string>
#include <vector>

#define BUTTON_OUTPUT 1
#define BUTTON_BROWSE 2

namespace winapi
{
main_window::main_window()
{
    std::memset(&main_wndclass, 0, sizeof main_wndclass);
    if (setup_main_wndclass())
    {
        create_main_window();
    }
}

main_window::~main_window()
{
    if (window != NULL)
        DestroyWindow(window);
    if (button_output != NULL)
        DestroyWindow(button_output);
    if (button_browse != NULL)
        DestroyWindow(button_browse);
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
    case WM_SIZE: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        const auto width = LOWORD(lParam);
        const auto height = HIWORD(lParam);
        window_object->on_size(width, height);
        break;
    }
    case WM_CREATE: {
        const auto create_struct = reinterpret_cast<CREATESTRUCT *>(lParam);
        const auto window_object = reinterpret_cast<main_window *>(create_struct->lpCreateParams);
        window_object->on_create(hWnd);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window_object));
        break;
    }
    case WM_GETMINMAXINFO: {
        LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
        lpMMI->ptMinTrackSize.x = GetSystemMetrics(SM_CXSCREEN) / 3;
        lpMMI->ptMinTrackSize.y = GetSystemMetrics(SM_CYSCREEN) / 5;
        break;
    }
    case WM_COMMAND: {
        const auto window_object_pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        const auto window_object = reinterpret_cast<main_window *>(window_object_pointer);
        window_object->on_command(wParam);
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
    main_wndclass.lpszClassName = window_class_name.c_str();
    main_wndclass.hInstance = (HINSTANCE)GetModuleHandle(NULL);
    main_wndclass.lpfnWndProc = WndProc;
    main_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    main_wndclass.hIcon = LoadIcon((HINSTANCE)GetModuleHandle(NULL), IDI_APPLICATION);
    main_wndclass.lpszMenuName = 0;
    main_wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    main_wndclass.style = CS_HREDRAW | CS_VREDRAW;
    main_wndclass.cbClsExtra = (int)GetClassLongPtr(window, GWLP_USERDATA);
    main_wndclass.cbWndExtra = 0;
    if (!RegisterClass(&main_wndclass))
        return 0;
    return 1;
}

bool main_window::create_main_window()
{
    const int screen_width = GetSystemMetrics(SM_CXSCREEN);
    const int screen_height = GetSystemMetrics(SM_CYSCREEN);

    RECT window_rect;
    window_rect.left = 0;
    window_rect.top = 0;
    window_rect.right = screen_width / 2;
    window_rect.bottom = screen_height / 2;

    AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW, NULL);
    const int window_height = window_rect.bottom - window_rect.top;
    const int window_width = window_rect.right - window_rect.left;

    const int window_x = (screen_width / 2) - (window_width / 2);
    const int window_y = (screen_height / 2) - (window_height / 2);

    const auto window_header = _T("febe_test");
    const auto flags = WS_OVERLAPPEDWINDOW;

    auto main_wnd = CreateWindow(window_class_name.c_str(), window_header, flags, window_x, window_y, window_width,
                                 window_height, NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), this);
    if (main_wnd != NULL)
        return 1;
    return 0;
}

bool main_window::on_create(HWND parent)
{
    window = parent;
    if (window != NULL)
    {
        auto result = create_static_text();
        result |= create_button_output();
        result |= create_button_browse();
        result |= create_text_box();
        return result;
    }
    return 0;
}

bool main_window::create_button_output()
{
    const auto class_name = _T("BUTTON");
    const auto text_in_window = _T("Output");
    const auto flags = WS_CHILD | WS_VISIBLE | BS_FLAT | BS_VCENTER | BS_PUSHBUTTON;

    button_output = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100, 25, window,
                                 (HMENU)BUTTON_OUTPUT, NULL, NULL);
    if (button_output != NULL)
        return 1;
    return 0;
}

bool main_window::create_button_browse()
{
    const auto class_name = _T("BUTTON");
    const auto text_in_window = _T("Browse");
    const auto flags = WS_CHILD | WS_VISIBLE | BS_FLAT | BS_VCENTER | BS_PUSHBUTTON;

    button_browse = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100, 22, window,
                                 (HMENU)BUTTON_BROWSE, NULL, NULL);
    if (button_browse != NULL)
        return 1;
    return 0;
}

bool main_window::create_static_text()
{
    const auto class_name = _T("STATIC");
    const auto text_in_window = _T("Input file path:");
    const auto flags = WS_VISIBLE | WS_CHILD;

    static_text = CreateWindowEx(WS_EX_TRANSPARENT, class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT,
                                 100, 25, window, NULL, NULL, NULL);

    if (static_text != NULL)
        return 1;
    return 0;
}

bool main_window::create_text_box()
{
    const auto class_name = _T("EDIT");
    const auto text_in_window = _T("");
    const auto flags = WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT;

    text_box = CreateWindow(class_name, text_in_window, flags, CW_USEDEFAULT, CW_USEDEFAULT, 100, 20, window, NULL,
                            NULL, NULL);
    if (text_box != NULL)
        return 1;
    return 0;
}

bool main_window::on_size(const int width, const int height)
{
    auto result = move_text_box(width, height);
    result |= move_button_output(width, height);
    result |= move_button_browse(width, height);
    result |= move_static_text(width, height);
    return result;
}

bool main_window::move_button_output(const int width, const int height)
{
    const int button_height = 25;
    const int button_width = 100;

    const int button_x = (width / 2 - button_width / 2);
    const int button_y = ((height / 2 - button_height / 2) + button_height * 2);

    const auto result = MoveWindow(button_output, button_x, button_y, button_width, button_height, TRUE);

    return result;
}

bool main_window::move_button_browse(const int width, const int height)
{
    const int button_height = 22;
    const int button_width = 100;

    const int button_x = (width / 2 + width / 4) + button_width / 50;
    const int button_y = (height / 2) - button_height / 2;

    const auto result = MoveWindow(button_browse, button_x, button_y, button_width, button_height, TRUE);

    return result;
}

bool main_window::move_text_box(const int width, const int height)
{
    const int text_box_height = 20;
    const int text_box_width = width / 2;

    const int text_box_x = (width / 2) - (text_box_width / 2);
    const int text_box_y = (height / 2) - (text_box_height / 2);

    const auto result = MoveWindow(text_box, text_box_x, text_box_y, text_box_width, text_box_height, TRUE);

    return result;
}

bool main_window::move_static_text(const int width, const int height)
{
    const int static_text_width = 100;
    const int static_text_height = static_text_width / 4;

    const int static_text_x = (width / 2 - width / 4) - static_text_width;
    const int static_text_y = (height / 2) - (20 / 2);

    const auto result =
        MoveWindow(static_text, static_text_x, static_text_y, static_text_width, static_text_height, TRUE);

    return result;
}

bool main_window::on_command(WPARAM wParam)
{
    switch (LOWORD(wParam))
    {
    case BUTTON_OUTPUT: {
        on_button_output();
        break;
    }
    case BUTTON_BROWSE: {
        open_file_browse();
        break;
    }
    }
    return 0;
}

bool main_window::on_button_output()
{
    GetWindowText(text_box, file_path, GetWindowTextLength(text_box) + 1);
    if (file_path != 0)
    {
        auto reader = readers::factory::create(file_path);
        if (reader != nullptr)
        {
            auto text = reader->get_content_from_file();
            if (text != nullptr)
            {
                std::wstring str;
                for (auto i = 0; i < text->size(); i++)
                {
                    str += text->at(i) + L"\n";
                }
                MessageBox(NULL, str.c_str(), file_path, MB_OK);
            }
            else
            {
                MessageBox(NULL, L"File is not found", L"Error", MB_OK | MB_ICONHAND);
            }
        }
        else
        {
            MessageBox(NULL, L"File extension is not supported", L"Error", MB_OK | MB_ICONHAND);
        }
    }
    return 1;
}

bool main_window::open_file_browse()
{
    OPENFILENAME open_file_name;
    const LPCWSTR filters = L"Text files *.txt\0*.txt\0"
                            L"JSON files *.json\0*.json\0";
    const auto flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ZeroMemory(&open_file_name, sizeof(OPENFILENAME));
    ZeroMemory(file_path, sizeof(wchar_t));
    open_file_name.lStructSize = sizeof(OPENFILENAME);
    open_file_name.hInstance = (HINSTANCE)GetStockObject(NULL);
    open_file_name.hwndOwner = window;
    open_file_name.lpstrFile = file_path;
    open_file_name.nMaxFile = sizeof(file_path);
    open_file_name.lpstrFilter = filters;
    open_file_name.nFilterIndex = 1;
    open_file_name.lpstrFileTitle = NULL;
    open_file_name.nMaxFileTitle = 0;
    open_file_name.lpstrInitialDir = NULL;
    open_file_name.Flags = flags;

    if (GetOpenFileName(&open_file_name))
    {
        if (SetWindowText(text_box, file_path))
            return 1;
    }
    return 0;
}

bool main_window::run(int nCmdShow)
{
    if (window != NULL)
    {
        ShowWindow(window, nCmdShow);
        UpdateWindow(window);
        MSG lpMsg;
        while (GetMessage(&lpMsg, NULL, 0, 0))
        {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    }
    return GetLastError();
}
}
