#include "language.h"
#include "open_and_output_text.h"
#include "program_notifications.h"

#include <iostream>
#include <string>

int main()
{
    system("chcp 1251>nul");

    output_notifications(language::unknown, 0);

    language program_language = choice_of_interface_language();

    output_notifications(program_language, 1);

    if (program_language == language::unknown) { program_language = language::english; }

    std::string file_name = input_file_name();

    std::vector<std::string> text;
    std::string message;
    std::tie (text, message) = open_file(program_language, file_name);
    std::cout << message << std::endl;
    for (std::string i : text)
    {
        std::cout << i << std::endl;
    }
    return 0;
}