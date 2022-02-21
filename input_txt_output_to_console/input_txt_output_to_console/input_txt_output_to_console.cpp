#include "language.h"
#include "system_notifications.h"
#include "errors.h"

#include <iostream>
#include <fstream>
#include <string>


auto open_file_and_output_text(language language)
{
    std::ifstream file_handler;
    std::string text;
    std::string file;
    std::cin >> file;
    file_handler.open(file.c_str());
        if (file_handler.is_open())
    {
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


int main()
{
    system("chcp 1251>nul");

    output_of_welcome_phrase();

    language language = choice_of_interface_language();

    open_file_and_output_text(language);
    return 0;
}