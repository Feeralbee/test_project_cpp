#include "readers/factory.h"
#include "readers/data.h"
#include "readers/json.h"
#include "readers/txt.h"

#include <filesystem>
#include <memory>

namespace readers
{
std::unique_ptr<data> factory::create(std::filesystem::path path)
{
    if (path.extension() == ".txt")
    {
        return std::make_unique<readers::txt>(readers::txt());
    }
    else if (path.extension() == ".json")
    {
        return std::make_unique<readers::json>(readers::json());
    }
    else
    {
        return nullptr;
    }
}
}
