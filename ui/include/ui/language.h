#pragma once
#include <string>
namespace ui
{
namespace language
{
enum class id
{
    russian,
    english
};
id interface_language_selection(std::string user_selection);
}
}
