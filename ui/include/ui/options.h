#pragma once
#include <new>
namespace ui
{
enum class language_id
{
    russian,
    english
};
class options
{
  protected:
    language_id language;
    options() = default;
    ~options() = default;

  public:
    void set_en_language();
    void set_ru_language();
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
