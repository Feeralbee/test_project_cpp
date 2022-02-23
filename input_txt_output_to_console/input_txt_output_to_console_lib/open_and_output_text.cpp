#include "application_errors.h"
#include "application_notifications.h"

#include <fstream>
#include <iostream>
#include <string>


void open_file_and_output_text(language language)
{
    std::ifstream file_handler;
    std::string text;
    std::string file;
    std::cin >> file;
    file_handler.open(file.c_str());
    if (file_handler.is_open())
    {
        notification_about_file_openning(language);
        while (getline(file_handler, text))
        {
            std::cout << text << std::endl;
        }
        file_handler.close();
    }
    else
    {
        error_finding_the_file_at_the_specified_path(language);
    }

}