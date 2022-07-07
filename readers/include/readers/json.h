#pragma once
#include "readers/data.h"

#include <filesystem>
#include <istream>
#include <json/json.h>
#include <json/writer.h>
#include <memory>
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
    void parse(std::istream &file_handler, std::vector<std::wstring> &content);
    void write_content(Json::Value root, std::vector<std::wstring> &content);

  public:
    json(std::filesystem::path file_path);
    virtual std::unique_ptr<std::vector<std::wstring>> get_content_from_file() override;
};
}
