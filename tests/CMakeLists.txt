cmake_minimum_required(VERSION 3.16)

file(GLOB SOURCES "*.cpp")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_compile_definitions(USER_DEFINITION)

enable_testing()

foreach(test_src_code ${SOURCES})
    get_filename_component(test_exec_name ${test_src_code} NAME_WE)
    add_executable(${test_exec_name} ${test_src_code})
    # target_compile_features(${test_exec_name} PRIVATE cxx_std_11)
    target_compile_options(${test_exec_name} PRIVATE -fsanitize=address)
    target_link_options(${test_exec_name} PRIVATE -fsanitize=address)
    add_test(
        NAME ${test_exec_name}
        COMMAND $<TARGET_FILE:${test_exec_name}>
    )
endforeach(test_src_code ${SOURCES})