#pragma once
#include "readers/data.h"

#include <filesystem>
#include <memory>

namespace readers
{
class factory
{
  public:
    static std::unique_ptr<data> create(std::filesystem::path path);
};
}