add_library(readers     
    STATIC
        src/txt.cpp
        src/json.cpp
        src/factory.cpp
        src/data.cpp

        include/readers/txt.h
        include/readers/json.h
        include/readers/factory.h
        include/readers/data.h
)

target_include_directories(readers
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(readers
    PUBLIC
        unicode_helper 
        CONAN_PKG::jsoncpp
)

#####################Test#####################
add_executable(readers_test 
    tests/$<IF:$<BOOL:${WIN32}>,windows,linux>/txt_test.cpp
    tests/json_test.cpp
    tests/factory_test.cpp
)

target_link_libraries(readers_test 
    PRIVATE 
        readers
        CONAN_PKG::gtest
)

add_dependencies(readers_test copy_test_resources)

set_target_properties(
    readers_test PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${FEBE_EXE_OUTPUT_DIRECTORY}")

add_test(NAME readers_test
	COMMAND readers_test
	WORKING_DIRECTORY ${FEBE_EXE_OUTPUT_DIRECTORY}
)

if(MSVC_IDE)
	set_target_properties(readers_test readers PROPERTIES
        	FOLDER readers)
endif()
