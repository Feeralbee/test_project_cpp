#pragma once

namespace ui
{
enum class language_id
{
    russian,
    english
};
class language
{
  private:
    language_id language;
    language() = default;
    ~language() = default;

  public:
    void set_language()
    {
        language = language_id::english;
    }
};
language_id parse_language_argument(int argc, char *argv[]);
}
