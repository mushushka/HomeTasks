cmake_minimum_required(VERSION 3.8)
project(stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES stack.cpp stack.h stack_test.cpp)
add_executable(stack ${SOURCE_FILES})