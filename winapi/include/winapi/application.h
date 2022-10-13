#pragma once
#include <Windows.h>
#include <memory>
#include <string>
#include <tchar.h>

namespace winapi
{
class application
{
  private:
    std::wstring programm_name = _T("febe_test");

  public:
    application() = default;
    ~application() = default;
    static std::unique_ptr<application> get_application();
    std::wstring get_program_name();
};
}