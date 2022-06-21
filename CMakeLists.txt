cmake_minimum_required(VERSION 3.0)
project(playground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

find_package(Eigen3 3.4.0 REQUIRED CONFIG PATHS "c:/Program Files (x86)/Eigen3")

add_executable(playground main.cpp)

target_link_libraries(playground PUBLIC Eigen3::Eigen)
