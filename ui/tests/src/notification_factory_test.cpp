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
    const auto test = ui::notifications_factory::make(options);
    ASSERT_TRUE(dynamic_cast<ui::notifications_en *>(test.get()) != nullptr);
}

TEST(testing_of_creating, notification_rus)
{
    ui_test::options_test options;
    options.set_language(ui::options::language_id::russian);
    const auto test = ui::notifications_factory::make(options);
    ASSERT_TRUE(dynamic_cast<ui::notifications_rus *>(test.get()) != nullptr);
}
TEST(testing_of_creating, notifications_in_default_language)
{
    ui_test::options_test options;
    const auto test = ui::notifications_factory::make(options);
    ASSERT_TRUE(dynamic_cast<ui::notifications_en *>(test.get()) != nullptr);
}
