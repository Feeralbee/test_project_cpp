#pragma once

#include "winapi/control.h"

#include <Windows.h>

namespace winapi
{
class button_browse : public control
{
  public:
    bool on_command(WPARAM wParam, LPARAM lParam);
};
}
