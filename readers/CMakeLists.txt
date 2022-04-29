add_library(readers     
    STATIC
        src/txt.cpp

        include/readers/txt.h
)

target_include_directories(readers
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/include
)

#####################Test#####################
add_executable(readers_test 
    tests/txt_test.cpp
)

target_link_libraries(readers_test 
    PRIVATE 
        readers
        CONAN_PKG::gtest
)