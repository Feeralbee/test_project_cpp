#include <iostream>
#include "language.h"

void language_input_error()
{
	std::cout << "Error! You have entered an unavailable language! Try again: ";
	choice_of_interface_language();
}

void error_finding_the_file_at_the_specified_path_ru()
{
	std::cout << "Ошибка! Путь к файлу введен неправильно!";
}

void error_finding_the_file_at_the_specified_path_en()
{
	std::cout << "Error! The path to the file is entered incorrectly!";
}

