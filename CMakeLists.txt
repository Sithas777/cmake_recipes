cmake_minimum_required(VERSION 3.0)
project(playground)

set(CMAKE_CXX_STANDARD 20)

add_executable(playground main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(playground PUBLIC "IS_LINUX")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(playground PUBLIC "IS_MACOS")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(playground PUBLIC "IS_WINDOWS")
endif()
