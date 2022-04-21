SET(SOURCE_FILES
    open_and_output_text.cpp
)

SET(HEADER_FILES
    open_and_output_text.h
)

add_library(input_txt_output_to_console_lib     STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_include_directories(input_txt_output_to_console_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

