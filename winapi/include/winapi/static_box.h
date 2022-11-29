#pragma once
#include "winapi/control.h"

namespace winapi
{
class static_box : public control
{
  private:
    virtual std::tuple<int, int, int, int> calculate_position(int parent_width, int parent_height);
};
}
