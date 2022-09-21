add_executable(win_api WIN32
    src/main.cpp
)


target_link_libraries(win_api   
    readers
    ui
)