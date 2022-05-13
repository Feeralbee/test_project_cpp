     
if(WIN32)
    SET(PLATFORM_DIRECTORY "windows")
else()
    SET(PLATFORM_DIRECTORY "linux")
endif()

add_library(ui  STATIC
    src/notifications.cpp 
    src/${PLATFORM_DIRECTORY}/std_out.cpp
    src/input.cpp
    src/text.cpp

    include/ui/language.h
    include/ui/notifications.h
    include/ui/std_out.h
    include/ui/input.h
    include/ui/text.h
)    

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/include
)
######################Tests###########################
add_executable(ui_test 
    tests/program_notifications_test.cpp
)

target_link_libraries(ui_test   
    ui
    CONAN_PKG::gtest
)