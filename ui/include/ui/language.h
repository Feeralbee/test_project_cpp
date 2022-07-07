#pragma once

enum class language
{
    russian,
    english
};

language parse_language_argument(int argc, char *argv[]);
