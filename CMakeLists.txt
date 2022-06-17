cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(cmake-recipes LANGUAGES CXX)

option(USE_LIBRARY "Do you want compile source into a library?" OFF)
set(BUILD_SHARED_LIBS OFF)
list(APPEND _sources FizzBuzz.hpp FizzBuzz.cpp)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")

message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

if (USE_LIBRARY)
    add_library(fizzbuzz ${_sources})
    add_executable(main main.cpp)
    target_link_libraries(main fizzbuzz)
else()
    add_executable(main main.cpp ${_sources})
endif()
