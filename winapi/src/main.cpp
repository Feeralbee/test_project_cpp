#include "winapi/application.h"
#include "winapi/main_window.h"

#include <Windows.h>
#include <string>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int nCmdShow)
{
    const auto application = winapi::application::get_application();
    const auto main_window = application->create_main_window();
    if (main_window->create())
        main_window->run(nCmdShow);
    return 0;
}
