#pragma once
#include "winapi/main_window.h"

#include <Windows.h>
#include <memory>
#include <string>
#include <tchar.h>

namespace winapi
{
class application
{
  private:
  public:
    application() = default;
    ~application() = default;
    static std::unique_ptr<application> get_application();
    std::unique_ptr<main_window> create_main_window();
};
}