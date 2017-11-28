cmake_minimum_required(VERSION 3.8)
project(priorityQueueL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES priorityQueueL.h priorityQueueL.cpp priorityQueueL_test.cpp)
add_executable(priorityQueueL ${SOURCE_FILES})