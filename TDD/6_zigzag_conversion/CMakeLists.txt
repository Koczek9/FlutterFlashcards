cmake_minimum_required(VERSION 3.15...3.21)
project(longest_substring)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(tests)

add_library(
  solution_class 
  solution.cpp 
  solution.h
)

add_executable(longest_substring main.cpp)

target_link_libraries(longest_substring PUBLIC solution_class)
