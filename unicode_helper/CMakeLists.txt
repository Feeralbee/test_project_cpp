add_library(unicode_helper STATIC
	include/unicode_helper/multibyte_to_wchar.h
	
	src/multibyte_to_wchar.cpp
)

set_property(TARGET unicode_helper PROPERTY CXX_STANDARD 14)

target_include_directories(unicode_helper
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)
######################Tests###########################
add_executable(unicode_helper_test 
    tests/multibyte_to_wchar_test.cpp
)

target_link_libraries(unicode_helper_test   
    unicode_helper
    CONAN_PKG::gtest
)

add_test(NAME unicode_helper_test
	COMMAND unicode_helper_test
)


if(MSVC_IDE)
	set_target_properties(unicode_helper_test unicode_helper PROPERTIES
        	FOLDER unicode_helper)
endif()

