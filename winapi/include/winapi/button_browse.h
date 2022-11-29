#pragma once

#include "winapi/control.h"

#include <Windows.h>
#include <string>

namespace winapi
{
class button_browse : public control
{
  private:
    virtual std::tuple<int, int, int, int> calculate_position(int parent_width, int parent_height);

  public:
    bool on_push(std::wstring &directory);
};
}
