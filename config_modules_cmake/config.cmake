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

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


if(MSVC_IDE)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()
