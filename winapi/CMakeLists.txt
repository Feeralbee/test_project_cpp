add_executable(win_api WIN32
    src/main.cpp
    src/main_window.cpp
    src/application.cpp
    src/control.cpp
    src/static_text.cpp
    src/static_box.cpp
    src/combo_box.cpp
    src/list_box.cpp
    src/button_browse.cpp

    include/winapi/main_window.h
    include/winapi/application.h
    include/winapi/control.h
    include/winapi/button_browse.h
    include/winapi/list_box.h
    include/winapi/combo_box.h
    include/winapi/static_text.h
    include/winapi/static_box.h
    include/winapi/messages.h
)

target_include_directories(win_api
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(win_api   
    readers
)

add_definitions(-DUNICODE -D_UNICODE)
