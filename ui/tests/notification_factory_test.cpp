#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/notifications_en.h"
#include "ui/notifications_rus.h"
#include "ui/options.h"

#include <gtest/gtest.h>

TEST(testing_of_creating, notification_en)
{
    auto &lang = ui::options::get_options();
    lang.set_en_language();
    const auto test = ui::notifications_factory::make();
    ASSERT_TRUE(dynamic_cast<ui::notifications_en *>(test.get()) != nullptr);
}

TEST(testing_of_creating, notification_rus)
{
    auto &lang = ui::options::get_options();
    lang.set_ru_language();
    const auto test = ui::notifications_factory::make();
    ASSERT_TRUE(dynamic_cast<ui::notifications_rus *>(test.get()) != nullptr);
}
