#pragma once
#include <string>

enum class language
{
	russian,
	english,
	unknown
};

std::string input_user_language();
language interface_language_selection(std::string user_selection);
