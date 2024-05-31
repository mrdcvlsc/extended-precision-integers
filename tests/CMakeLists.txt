cmake_minimum_required(VERSION 3.16)
project(extended_precision_integers VERSION 1.0.0)

file(GLOB SOURCES "*.cpp")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_compile_definitions(USER_DEFINITION)

if(WIN32)
    # disable windows asan for now since I don't know how to make it work
    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /fsanitize=address")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif()

enable_testing()

foreach(test_src_code ${SOURCES})
    get_filename_component(test_exec_name ${test_src_code} NAME_WE)
    add_executable(${test_exec_name} ${test_src_code})
    add_test(
        NAME ${test_exec_name}
        COMMAND $<TARGET_FILE:${test_exec_name}>
    )
endforeach(test_src_code ${SOURCES})

