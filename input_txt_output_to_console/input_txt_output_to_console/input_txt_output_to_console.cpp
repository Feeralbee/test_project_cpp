#include <iostream>
#include <fstream>
#include <string>
#include "language.h"
#include "errors.h"
#include "system_notifications.h"


void open_file_and_output_text(std::string language_index)
{
    std::ifstream File_handler;
    std::string text;
    std::string file;
    std::cin >> file;
    File_handler.open(file.c_str());
        if (File_handler.is_open())
    {
        while (getline(File_handler, text))
        {
            std::cout << text << std::endl;
        }
        File_handler.close();
    }
    else
    {
            if (language_index == "ru")
            {
                error_finding_the_file_at_the_specified_path_ru();

            }

            if (language_index == "en")
            {
                error_finding_the_file_at_the_specified_path_en();

            }

    }

}


int main()
{
    system("chcp 1251>nul");

    output_of_welcome_phrase();

    bool language = choice_of_interface_language();
    if ( language == true)
    {
        open_file_and_output_text("ru");
    }
    else if (language == false)
    {
        open_file_and_output_text("en");
    }
    return 0;
}
