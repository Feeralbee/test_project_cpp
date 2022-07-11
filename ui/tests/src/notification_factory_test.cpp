#include "ui/notification_factory.h"
#include "ui/notifications.h"
#include "ui/notifications_en.h"
#include "ui/notifications_rus.h"
#include "ui/options.h"
#include "ui_test/options_helper.h"

#include <gtest/gtest.h>

TEST(testing_of_creating, notification_en)
{
    ui_test::options_test options;
    options.set_language(ui::options::language_id::english);
    const auto test = ui::notifications_factory::make();
    ASSERT_TRUE(dynamic_cast<ui::notifications_en *>(test.get()) != nullptr);
}

TEST(testing_of_creating, notification_rus)
{
    auto &options = ui::options::get_options();
    options.set_language(ui::options::language_id::russian);
    const auto test = ui::notifications_factory::make();
    ASSERT_TRUE(dynamic_cast<ui::notifications_rus *>(test.get()) != nullptr);
}
