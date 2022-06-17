cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(cmake-recipes LANGUAGES CXX)

option(USE_LIBRARY "Do you want compile source into a library?" OFF)
set(BUILD_SHARED_LIBS OFF)
list(APPEND _sources FizzBuzz.hpp FizzBuzz.cpp)

if (USE_LIBRARY)
    add_library(fizzbuzz ${_sources})
    add_executable(main main.cpp)
    target_link_libraries(main fizzbuzz)
else()
    add_executable(main main.cpp ${_sources})
endif()
