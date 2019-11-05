cmake_minimum_required(VERSION 3.14)
project(pen)

set(CMAKE_CXX_STANDARD 14)

add_executable(pen src/main.cpp src/Pen.h src/Pen.cpp src/FailedToInitialize.cpp src/FailedToInitialize.h)
target_link_libraries(pen -lsdl2 -lsdl2_image)