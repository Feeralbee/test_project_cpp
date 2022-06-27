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
  private:
    std::filesystem::path _path;

  public:
    txt(std::filesystem::path file_path);
    virtual std::optional<std::vector<std::wstring>> get_content_from_file() override;

  protected:
    std::vector<std::wstring> read(std::wistream &file_handler);
};
}
