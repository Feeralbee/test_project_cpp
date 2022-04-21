#include "language.h"
#include "open_and_output_text.h"
#include "program_notifications.h"

#include <string>
#include <fstream>


int main()
{
    output_notifications(language::unknown, notifications_and_errors::welcome_phrase);

    auto user_selection = input_user_language();

    language program_language = interface_language_selection(user_selection);


    output_notifications(program_language, notifications_and_errors::enter_file_path);

    if (program_language == language::unknown) { program_language = language::english; }

    std::string file_name = input_file_name();

    std::ifstream* file_handler;
    bool result_of_opening_file;
    std::tie(file_handler, result_of_opening_file) = open_file(file_name);

    switch (result_of_opening_file) 
    {
    case false:
        output_notifications_with_endl(program_language, notifications_and_errors::path_incorrectly);
        break;
    case true:
        output_notifications_with_endl(program_language, notifications_and_errors::file_has_openned);

        std::vector<std::string> strings_from_file = read_file(file_name, file_handler);

        output_text_from_file(strings_from_file);
        break;
    }
    return 0;
}