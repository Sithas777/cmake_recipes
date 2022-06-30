cmake_minimum_required(VERSION 3.22)
project(playground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

find_package(Boost 1.78.0 REQUIRED COMPONENTS system)

add_executable(playground main.cpp)
target_include_directories(playground PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(playground PRIVATE ${Boost_LIBRARIES})
