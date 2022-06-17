#include "ui/std_out.h"

#include <Windows.h>
#include <cstdlib>
#include <stdio.h>

namespace ui
{
namespace platform
{
void init_out()
{
    std::system("cls");
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
}
void init_input()
{
    SetConsoleCP(1251);
}

}
}
