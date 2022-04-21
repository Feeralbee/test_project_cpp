#include "std_out.h"
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>



void platform::init_out()
{
    std::system("cls");
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
}

