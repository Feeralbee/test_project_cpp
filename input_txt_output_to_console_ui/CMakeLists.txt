     
if(WIN32)
    SET(PLATFORM_DIRECTORY "windows")
else()
    SET(PLATFORM_DIRECTORY "linux")
endif()

SET (SOURCE_FILES
    program_notifications.cpp 
    ${PLATFORM_DIRECTORY}/std_out.cpp
    language.cpp
)

SET(HEADER_FILES
    language.h
    program_notifications.h
    std_out.h
)


add_library(input_txt_output_to_console_ui  STATIC
     ${SOURCE_FILES}
     ${HEADER_FILES}
)    

target_include_directories(input_txt_output_to_console_ui
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
