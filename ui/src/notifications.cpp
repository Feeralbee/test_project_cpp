#include "ui/notifications.h"
#include "ui/language.h"

#include <iostream>
#include <string>

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
            message = u8"Error! The file was not found by this path!\n";
        }
        else if (index_of_notification == notifications_id::file_extension_incorrect)
        {
            message = u8"The entered file extension is not supported\n";
        }
    }
    else if (program_language == ui::language::id::russian)
    {
        if (index_of_notification == notifications_id::enter_file_path)
        {
            message = "Введите путь к файлу: ";
        }
        else if (index_of_notification == notifications_id::file_has_openned)
        {
            message = "Файл открылся!\n";
        }
        else if (index_of_notification == notifications_id::file_wasnt_found)
        {
            message = "Ошибка! По данному пути файл не найден!\n";
        }
        else if (index_of_notification == notifications_id::file_extension_incorrect)
        {
            message = "Введенное расширение файла не поддерживается!\n";
        }
    }
    return message;
}
}
