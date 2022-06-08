cmake_minimum_required(VERSION 3.2)

project(febe)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_DISABLE_CHECK_COMPILER)

enable_testing()

get_property(FEBE_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if (FEBE_IS_MULTI_CONFIG)
    set(FEBE_BUILD_TYPE $<CONFIG>)
    set(CMAKE_CONFIGURATION_TYPES Debug Release)
    set(FEBE_EXE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/${FEBE_BUILD_TYPE})
else()
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
        set(CMAKE_BUILD_TYPE Debug)
    endif()
    set(FEBE_BUILD_TYPE ${CMAKE_BUILD_TYPE})
    set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE})
    set(FEBE_EXE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
                                                                            
include(conan.cmake)

conan_cmake_run(CONANFILE conanfile.py
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

add_subdirectory(main)
add_subdirectory(readers)
add_subdirectory(ui)
add_subdirectory(test_resources)

