cmake_minimum_required(VERSION 3.8)
project(priorityqueuel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES priorityqueuel.h priorityqueuel.cpp priorityqueuel_test.cpp)
add_executable(priorityqueuel ${SOURCE_FILES})