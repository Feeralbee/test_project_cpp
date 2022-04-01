cmake_minimum_required(VERSION 3.2)

project(input_txt_output_to_console)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_DISABLE_CHECK_COMPILER)

include(conan.cmake)


conan_cmake_run(CONANFILE conanfile.py
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

add_subdirectory(input_txt_output_to_console)
add_subdirectory(input_txt_output_to_console_lib)
add_subdirectory(input_txt_output_to_console_lib_test)
add_subdirectory(input_txt_output_to_console_ui)
add_subdirectory(input_txt_output_to_console_ui_test)

