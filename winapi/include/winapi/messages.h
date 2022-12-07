#pragma once
#include <Windows.h>

enum messages
{
    FILE_PATH_WAS_INIT = WM_USER + 1,
    COMBO_BOX_CURSEL_CHANGED,
    LIST_BOX_CURSEL_CHANGED,
};