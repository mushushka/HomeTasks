cmake_minimum_required(VERSION 3.8)
project(ex)

add_subdirectory(./dlib dlib_build)


    find_package(OpenCV REQUIRED)
    if (OpenCV_FOUND)
        include_directories(${OpenCV_INCLUDE_DIRS})

        add_executable(main src/main.cpp)
        target_link_libraries(main dlib::dlib ${OpenCV_LIBS} )
    else()
        message("OpenCV not found")
    endif()

