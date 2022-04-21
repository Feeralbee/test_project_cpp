#include "open_and_output_text.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

std::string input_file_name()
{
    std::string file_path;
    std::cin >> file_path;
    return file_path;
}

std::tuple<std::ifstream*, bool> open_file(std::string file_path)
{
    std::ifstream file_handler;
    std::string message;
    file_handler.open(file_path.c_str());
    if (file_handler.is_open())
    {
        return make_tuple(&file_handler, true);
        file_handler.close();
    }
    else
    {
        return make_tuple(&file_handler, false);
    }

}

std::vector<std::string>read_file(std::string file, std::ifstream* file_handler)
{
    std::string text;
    std::vector<std::string> strings_of_text;
    int i = 0;
    while (getline(*file_handler, text))
    {
        strings_of_text.push_back(text);
    }
    return strings_of_text;
}

void output_text_from_file(std::vector<std::string> text)
{
    for (std::string i : text)
    {
        std::cout << i << std::endl;
    }
}