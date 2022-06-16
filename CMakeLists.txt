cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES CXX)

add_library(fizz-buzz STATIC FizzBuzz.hpp FizzBuzz.cpp)

add_executable(link-library link-library.cpp)

target_link_libraries(link-library fizz-buzz)
