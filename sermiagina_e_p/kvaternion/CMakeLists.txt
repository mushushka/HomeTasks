cmake_minimum_required(VERSION 3.8)
project(kvaternion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES kvaternion.h kvaternion.cpp kvaternion_test.cpp)
add_executable(kvaternion ${SOURCE_FILES})