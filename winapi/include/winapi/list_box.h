#pragma once
#include "winapi/control.h"

#include <Windows.h>

namespace winapi
{
class list_box : public control
{
  private:
    virtual std::tuple<int, int, int, int> calculate_position(int parent_width, int parent_height);

  public:
    LRESULT set_item_data(WPARAM value, LPARAM index);
    LRESULT get_item_data(WPARAM index);
    LRESULT set_cursel(WPARAM index);
    LRESULT get_cursel();
    LRESULT insert_string(LPARAM string);
};
}
