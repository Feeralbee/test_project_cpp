add_executable(input_txt_output_to_console 
    input_txt_output_to_console.cpp
)

target_link_libraries(input_txt_output_to_console   
    input_txt_output_to_console_lib
    input_txt_output_to_console_ui
)