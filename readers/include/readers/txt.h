#pragma once
#include "readers/data.h"

#include <filesystem>
#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace readers
{
class txt : public data
{
  private:
    std::unique_ptr<std::filesystem::path> _path;

  public:
    txt(const std::filesystem::path &file_path);
    virtual std::unique_ptr<std::vector<std::wstring>> get_content_from_file() override;

  protected:
    void read(std::wistream &file_handler, std::vector<std::wstring> &text_from_file);
};
}
