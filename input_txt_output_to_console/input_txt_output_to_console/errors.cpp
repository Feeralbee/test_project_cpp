#include "language.h"

#include <iostream>


void language_input_error()
{
	std::cout << "Error! You have entered an unavailable language! Try again: ";
}

void error_finding_the_file_at_the_specified_path(language language)
{
	if (language == language::russian)
	{
		std::cout << "Ошибка! Путь к файлу введен неправильно!";
	}
	else if (language == language::english)
	{
		std::cout << "Error! The path to the file is entered incorrectly!";
	}
}


