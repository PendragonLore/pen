cmake_minimum_required(VERSION 3.14)
project(pen)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(pen src/main.cpp src/FailedToInitialize.cpp src/FailedToInitialize.hpp src/Types.hpp src/Pen.hpp src/Window.cpp src/Window.hpp)
target_link_libraries(pen ${SDL2_LIBRARIES})