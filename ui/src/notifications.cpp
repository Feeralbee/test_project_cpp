#include "ui/notifications.h"

namespace ui
{
namespace notifications
{
void output(ui::language::id language, id index_of_notification)
{
    platform::init_out();
    std::cout << strings(language, index_of_notification);
}

std::string strings(ui::language::id language, id index_of_notification)
{
    std::string message;

    if (language == ui::language::id::english)
    {
        if (index_of_notification == id::enter_file_path)
        {
            message = u8"Enter file path: ";
        }
        else if (index_of_notification == id::file_has_openned)
        {
            message = u8"File has openned!\n";
        }
        else if (index_of_notification == id::path_incorrectly)
        {
            message = u8"Error! The path to the file is entered incorrectly!";
        }
    }
    else if (language == ui::language::id::russian)
    {
        if (index_of_notification == id::enter_file_path)
        {
            message = u8"Введите путь к файлу: ";
        }
        else if (index_of_notification == id::file_has_openned)
        {
            message = u8"Файл открылся!\n";
        }
        else if (index_of_notification == id::path_incorrectly)
        {
            message = u8"Ошибка! Путь к файлу введен неправильно!";
        }
    }
    return message;
}
}
}
