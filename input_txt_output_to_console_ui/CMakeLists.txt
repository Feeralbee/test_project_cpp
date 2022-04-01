add_library(input_txt_output_to_console_ui  STATIC
    program_notifications.cpp 
    program_notifications.h
    language.cpp
    language.h
)       

target_include_directories(input_txt_output_to_console_ui
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
