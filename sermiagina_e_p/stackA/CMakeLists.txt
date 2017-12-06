cmake_minimum_required(VERSION 3.8)
project(stackA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES stackA.h stackA.cpp stackA_test.cpp)
add_executable(stackA ${SOURCE_FILES})