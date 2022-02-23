#include "language.h"
#include "application_notifications.h"
#include "open_and_output_text.h"

#include <string>



int main()
{
    system("chcp 1251>nul");

    output_of_welcome_phrase();

    language language = choice_of_interface_language();

    open_file_and_output_text(language);
    return 0;
}