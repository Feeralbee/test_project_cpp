add_executable(input_txt_output_to_console_lib_test 
    open_and_output_text_test.cpp
)

target_link_libraries(input_txt_output_to_console_lib_test 
    PRIVATE 
        input_txt_output_to_console_lib
        CONAN_PKG::gtest
)



    