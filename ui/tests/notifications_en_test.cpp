#include "gtest/gtest.h"

#include "ui/notifications_en.h"

TEST(get_notifications_en, enter_file_path)
{
    ui::notifications_en notifications;
    ASSERT_EQ(u8"Enter file path: ", notifications.get_string(ui::notifications_id::enter_file_path));
}

TEST(get_notifications_en, file_has_openned)
{
    ui::notifications_en notifications;
    ASSERT_EQ(u8"File has openned!\n", notifications.get_string(ui::notifications_id::file_has_openned));
}

TEST(get_notifications_en, file_wasnt_found)
{
    ui::notifications_en notifications;
    ASSERT_EQ(u8"Error! The file was not found by this path!\n",
              notifications.get_string(ui::notifications_id::file_wasnt_found));
}

TEST(get_notifications_en, file_extension_incorrect)
{
    ui::notifications_en notifications;
    ASSERT_EQ(u8"The entered file extension is not supported\n",
              notifications.get_string(ui::notifications_id::file_extension_incorrect));
}
