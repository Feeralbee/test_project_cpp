add_executable(win_api WIN32
    src/main.cpp
    src/main_window.cpp
    src/application.cpp
    src/control.cpp
    src/control_builder.cpp

    include/winapi/main_window.h
    include/winapi/application.h
    include/winapi/control.h
    include/winapi/control_builder.h
)

target_include_directories(win_api
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(win_api   
    readers
)

add_definitions(-DUNICODE -D_UNICODE)
