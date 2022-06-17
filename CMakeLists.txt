cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(cmake-recipes LANGUAGES CXX)

option(USE_LIBRARY "Do you want compile source into a library?" OFF)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
list(APPEND _sources FizzBuzz.hpp FizzBuzz.cpp)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

list(APPEND flags "-fPIC" "-Wall")

if (NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic" "-fno-exceptions" "-fno-rtti")
endif()

message("C++ compiler flags ${CMAKE_CXX_FLAGS}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if (USE_LIBRARY)
    add_library(fizzbuzz ${_sources})
    target_compile_options(fizzbuzz PRIVATE ${flags})
    add_executable(main main.cpp)
    target_link_libraries(main fizzbuzz)
else()
    add_executable(main main.cpp ${_sources})
endif()

target_compile_options(main PRIVATE "-fno-exceptions" "-fno-rtti")

set_target_properties(main
        PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )
