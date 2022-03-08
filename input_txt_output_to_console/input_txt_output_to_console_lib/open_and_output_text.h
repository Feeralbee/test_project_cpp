#pragma once
#include "language.h"

#include <string>
#include <vector>
#include <tuple>

std::string input_file_name();
std::tuple<std::ifstream*, bool> open_file(std::string file_path);
std::vector<std::string>read_file(std::string file, std::ifstream* file_handler);
void output_text_from_file(std::vector<std::string> text);

