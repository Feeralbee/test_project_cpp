#pragma once
#include <new>

namespace ui
{
class options
{
  public:
    enum class language_id
    {
        russian,
        english
    };

  protected:
    language_id _language = language_id::english;
    options() = default;
    ~options() = default;

  public:
    void set_language(language_id lang);
    options(options &) = delete;
    void operator=(options &) = delete;
    void *operator new(std::size_t) = delete;
    void *operator new[](std::size_t) = delete;
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;
    language_id get_language();
    static options &get_options();
};
}
