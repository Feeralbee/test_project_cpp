#pragma once
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace ui
{
class text
{
  public:
    void output();
    text(std::vector<std::optional<std::string>> transmitted_strings_from_text);

  protected:
    std::vector<std::optional<std::string>> strings_from_text;
};

class TextTest : public text
{
  private:
    int count_lines;

  public:
    int get_count_lines();
    void output();
};

}
