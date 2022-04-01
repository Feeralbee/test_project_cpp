add_executable(input_txt_output_to_console_ui_test 
    language_test.cpp
    program_notifications_test.cpp
)

target_link_libraries(input_txt_output_to_console_ui_test   
    input_txt_output_to_console_ui
    CONAN_PKG::gtest
)