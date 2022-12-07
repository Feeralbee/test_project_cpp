#pragma once
#include "winapi/control.h"

#include <Windows.h>
#include <tuple>

namespace winapi
{
class static_text : public control
{
  private:
    virtual std::tuple<int, int, int, int> calculate_position(int parent_width, int parent_height);

  public:
    virtual bool on_command(WPARAM wparam)
    {
        wparam;
        return 1;
    };
};
}
