cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
set(SOURCE_FILES main.cpp Tests/ClassName.h Tests/test.cpp)
add_executable(untitled ${SOURCE_FILES} Tests/ClassName.h)
target_link_libraries(untitled gtest gtest_main)