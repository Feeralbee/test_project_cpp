#pragma once

#include "std_out.h"
#include "language.h"
#include <string>

enum class notifications_and_errors
{
	enter_file_path,
	file_has_openned,
	path_incorrectly,
	welcome_phrase
};

std::string notifications(language language, notifications_and_errors index_of_notification);
void output_notifications(language language, notifications_and_errors index_of_notification);
void output_notifications_with_endl(language language, notifications_and_errors index_of_notification);
