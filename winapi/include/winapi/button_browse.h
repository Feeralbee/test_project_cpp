#pragma once

#include "winapi/control.h"

#include <Windows.h>
#include <string>

namespace winapi
{
class button_browse : public control
{
  public:
    bool on_push(std::wstring &directory);
};
}
