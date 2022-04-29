#pragma once
#include <fstream>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class txt
{
  public:
    txt(std::string file_name);
    std::vector<std::optional<std::string>> get_strings();

  private:
    std::ifstream FileHandler;
    std::vector<std::optional<std::string>> strings_of_text;
};

} // namespace readers
