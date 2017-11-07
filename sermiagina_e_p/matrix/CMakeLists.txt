cmake_minimum_required(VERSION 3.8)
project(matrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrixU.h matrixU.cpp matrix_test.cpp matrixR.h matrixR.cpp)
add_executable(matrix ${SOURCE_FILES})