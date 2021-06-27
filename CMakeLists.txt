set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set (CMAKE_CXX_STANDARD 17)

project(HiringTest)

cmake_minimum_required(VERSION 3.10)


include_directories(.)
include_directories(googletest/googletest/include)

enable_testing()
add_subdirectory(googletest)

add_executable(TestSort test_sort.cpp)
target_link_libraries(TestSort gtest gtest_main)
add_test(TestSort TestSort)