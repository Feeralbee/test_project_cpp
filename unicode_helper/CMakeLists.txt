add_library(unicode_helper STATIC
	include/unicode_helper/multibyte_to_wchar.h
	
	src/multibyte_to_wchar.cpp
)

set_property(TARGET unicode_helper PROPERTY CXX_STANDARD 14)

target_include_directories(unicode_helper
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)


