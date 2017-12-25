cmake_minimum_required(VERSION 3.8)
project(stacka)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES stacka.h stacka.cpp stacka_test.cpp)
add_executable(stacka ${SOURCE_FILES})