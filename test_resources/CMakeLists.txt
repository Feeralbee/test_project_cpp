add_custom_target(copy_test_resources)

add_custom_command(TARGET copy_test_resources PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/test_files" "${FEBE_EXE_OUTPUT_DIRECTORY}/test_files"
)
