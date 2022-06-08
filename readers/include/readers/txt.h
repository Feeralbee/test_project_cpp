#pragma once
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class txt
{
  public:
    txt()
    {
    }
    std::optional<std::vector<std::wstring>> get_strings_from_file(std::filesystem::path file_path);

  protected:
    std::vector<std::wstring> read(std::wistream &file_handler);
};

}
