#include "ui/notifications.h"

namespace ui
{
notifications::notifications(language::id language)
{
    program_language = language;
}
void notifications::output(notifications_id index_of_notification)
{
    platform::init_out();
    std::cout << strings(index_of_notification);
}

std::string ui::notifications::strings(notifications_id index_of_notification)
{
    std::string message;

    if (program_language == ui::language::id::english)
    {
        if (index_of_notification == notifications_id::enter_file_path)
        {
            message = u8"Enter file path: ";
        }
        else if (index_of_notification == notifications_id::file_has_openned)
        {
            message = u8"File has openned!\n";
        }
        else if (index_of_notification == notifications_id::file_wasnt_found)
        {
            message = u8"Error! The file was not found by this path!";
        }
    }
    else if (program_language == ui::language::id::russian)
    {
        if (index_of_notification == notifications_id::enter_file_path)
        {
            message = u8"Введите путь к файлу: ";
        }
        else if (index_of_notification == notifications_id::file_has_openned)
        {
            message = u8"Файл открылся!\n";
        }
        else if (index_of_notification == notifications_id::file_wasnt_found)
        {
            message = u8"Ошибка! По данному пути файл не найден!";
        }
    }
    return message;
}
}
