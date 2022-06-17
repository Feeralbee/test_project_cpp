#pragma once
#include "readers/data.h"

#include <filesystem>
#include <istream>
#include <json/json.h>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class json : public data
{
  protected:
    std::vector<std::wstring> parse(std::istream &file_handler);
    std::vector<std::wstring> write_content(Json::Value root);

  public:
    json();
    virtual std::optional<std::vector<std::wstring>> get_content_from_file(std::filesystem::path file_path) override;
};
}
