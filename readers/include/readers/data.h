#pragma once
#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class data
{
  public:
    data();
    virtual ~data() = default;
    virtual std::optional<std::vector<std::wstring>> get_content_from_file() = 0;
};
}
