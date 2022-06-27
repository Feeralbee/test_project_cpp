#pragma once
#include "readers/data.h"

#include <filesystem>
#include <istream>
#include <json/json.h>
#include <json/writer.h>
#include <optional>
#include <string>
#include <vector>

namespace readers
{
class json : public data
{
  private:
    std::filesystem::path _path;
    Json::StreamWriterBuilder _builder;
    void setup_builder();

  protected:
    std::vector<std::wstring> parse(std::istream &file_handler);
    std::vector<std::wstring> write_content(Json::Value root);

  public:
    json(std::filesystem::path file_path);
    virtual std::optional<std::vector<std::wstring>> get_content_from_file() override;
};
}
