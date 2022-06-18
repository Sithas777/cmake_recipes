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

list(APPEND sources_with_max_optimization
        s_math_add.hpp
        s_math_add.cpp
        s_math_diff.hpp
        s_math_diff.cpp
        s_math_div.hpp
        s_math_div.cpp
        s_math_mult.hpp
        s_math_mult.cpp)
add_library(s_math
        STATIC ${sources_with_max_optimization})
target_link_libraries(main s_math)
target_compile_options(s_math PRIVATE -O3)

list(APPEND sources_with_lower_optimization s_math_div.hpp s_math_div.cpp)

foreach(_source IN LISTS sources_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
    message(STATUS "Appending -O2 for ${_source}")
endforeach()

target_compile_options(main PRIVATE "-fno-exceptions" "-fno-rtti")

message(STATUS "Querying source properties using plain syntax: ")
foreach(_source ${sources_with_max_optimization})
    get_source_file_property(_flags ${_source} COMPILE_FLAGS)
    message(STATUS "Source ${_source} has the following COMPILE_FLAGS: ${_flags}")
endforeach()

set_target_properties(main
        PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )
