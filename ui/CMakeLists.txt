add_library(ui  STATIC
    src/notifications.cpp 
    src/$<IF:$<BOOL:${WIN32}>,windows,linux>/std_out.cpp
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
        ${CMAKE_CURRENT_LIST_DIR}/include
)
######################Tests###########################
add_executable(ui_test 
    tests/text_test.cpp
    tests/notifications_test.cpp
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
