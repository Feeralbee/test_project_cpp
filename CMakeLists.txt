cmake_minimum_required(VERSION 3.2)

project(febe)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_DISABLE_CHECK_COMPILER)

include(conan.cmake)


conan_cmake_run(CONANFILE conanfile.py
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

add_subdirectory(main)
add_subdirectory(readers)
add_subdirectory(ui)

