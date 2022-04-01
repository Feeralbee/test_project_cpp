add_library(input_txt_output_to_console_lib     STATIC
    open_and_output_text.cpp
    open_and_output_text.h
)

target_include_directories(input_txt_output_to_console_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

