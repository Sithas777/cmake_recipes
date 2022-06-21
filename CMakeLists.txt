cmake_minimum_required(VERSION 3.0)
project(playground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

find_package(OpenMP REQUIRED)

add_executable(playground main.cpp)

target_link_libraries(playground PUBLIC OpenMP::OpenMP_CXX)
