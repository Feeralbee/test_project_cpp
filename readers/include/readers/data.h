#pragma once
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace readers
{
class data
{
  public:
    data();
    virtual ~data() = default;
    virtual std::unique_ptr<std::vector<std::wstring>> get_content_from_file() = 0;
};
}
