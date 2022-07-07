#include "readers/factory.h"
#include "readers/data.h"
#include "readers/json.h"
#include "readers/txt.h"

#include <filesystem>
#include <memory>

namespace readers
{
std::unique_ptr<data> factory::create(const std::filesystem::path &path)
{
    if (path.extension() == ".txt")
    {
        return std::make_unique<readers::txt>(readers::txt(path));
    }
    else if (path.extension() == ".json")
    {
        return std::make_unique<readers::json>(readers::json(path));
    }
    else
    {
        return nullptr;
    }
}
}
