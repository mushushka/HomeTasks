cmake_minimum_required(VERSION 3.8)
project(vec3dt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vec3dt.h vec3dt_test.cpp)
add_executable(vec3dt ${SOURCE_FILES})