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


macro(add_flags var)
    set(_add_flags_flags ${ARGN})
    list(JOIN _add_flags_flags " " _add_flags_flags)
    string(APPEND ${var} " ${_add_flags_flags}")
endmacro()

macro(add_clang_flags var)
    set(_add_clang_flags_flags ${ARGN})
    list(TRANSFORM _add_clang_flags_flags PREPEND -clang:)
    add_flags(${var} ${_add_clang_flags_flags})
endmacro()


add_clang_flags(CMAKE_CXX_FLAGS
    -Werror
    -Wall
    -Wextra
    -Wsuggest-destructor-override
    -Wsuggest-override

    # Reluctantly ignored warnings
    "-Wno-#warnings"
    -Wno-bitwise-op-parentheses
    -Wno-braced-scalar-init
    -Wno-char-subscripts
    -Wno-comment
    -Wno-deprecated
    -Wno-dynamic-class-memaccess
    -Wno-enum-compare
    -Wno-enum-compare-switch
    -Wno-extra-qualification
    -Wno-extra-tokens
    -Wno-ignored-pragmas
    -Wno-int-to-pointer-cast
    -Wno-int-to-void-pointer-cast
    -Wno-logical-not-parentheses
    -Wno-microsoft-cast
    -Wno-microsoft-enum-forward-reference
    -Wno-microsoft-exception-spec
    -Wno-microsoft-extra-qualification
    -Wno-microsoft-include
    -Wno-microsoft-pure-definition
    -Wno-microsoft-unqualified-friend
    -Wno-microsoft-using-decl
    -Wno-missing-braces
    -Wno-nonportable-include-path
    -Wno-null-conversion
    -Wno-overloaded-virtual
    -Wno-parentheses-equality
    -Wno-pessimizing-move
    -Wno-pointer-bool-conversion
    -Wno-pragma-pack
    -Wno-reorder
    -Wno-shift-negative-value
    -Wno-sign-compare
    -Wno-sizeof-pointer-div
    -Wno-string-compare
    -Wno-switch
    -Wno-undefined-inline
    -Wno-varargs
    -Wno-range-loop-analysis
    )
