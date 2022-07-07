#include "ui/notifications_rus.h"
#include "ui/notifications.h"
#include "ui/std_out.h"

#include <map>
#include <string>

namespace ui
{
notifications_rus::notifications_rus()
{
    strings_of_notifications[notifications_id::enter_file_path] = "Введите путь к файлу: ";
    strings_of_notifications[notifications_id::file_has_openned] = "Файл открылся!\n";
    strings_of_notifications[notifications_id::file_wasnt_found] = "Ошибка! По данному пути файл не найден!\n";
    strings_of_notifications[notifications_id::file_extension_incorrect] =
        "Введенное расширение файла не поддерживается!\n";
}
}
