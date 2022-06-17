#pragma once
#include "readers/data.h"

#include <filesystem>
#include <istream>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class txt : public data
{
  public:
    txt();
    virtual std::optional<std::vector<std::wstring>> get_content_from_file(std::filesystem::path file_path) override;

  protected:
    std::vector<std::wstring> read(std::wistream &file_handler);
};
}
