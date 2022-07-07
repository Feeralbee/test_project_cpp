add_library(ui  STATIC
    src/notification_factory.cpp 
    src/notifications.cpp 
    src/notifications_en.cpp 
    src/notifications_rus.cpp 
    src/$<IF:$<BOOL:${WIN32}>,windows,linux>/std_out.cpp
    src/input.cpp
    src/text.cpp
    src/options.cpp
    src/cmd_parsers.cpp

    include/ui/notifications.h
    include/ui/notifications_en.h 
    include/ui/notifications_rus.h
    include/ui/notification_factory.h
    include/ui/std_out.h
    include/ui/input.h
    include/ui/text.h
    include/ui/options.h
    include/ui/cmd_parsers.h
)    

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)
######################Tests###########################
add_executable(ui_test 
    tests/text_test.cpp
    tests/notifications_rus_test.cpp
    tests/notifications_en_test.cpp
)

target_link_libraries(ui_test   
    ui
    CONAN_PKG::gtest
)

add_test(NAME ui_test
	COMMAND ui_test
)


if(MSVC_IDE)
	set_target_properties(ui_test ui PROPERTIES
        	FOLDER ui)
endif()
