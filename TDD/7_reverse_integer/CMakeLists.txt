cmake_minimum_required(VERSION 3.15...3.21)
project(reverse_integer)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(tests)

add_library(
  solution_class 
  solution.cpp 
  solution.h
)

add_executable(reverse_integer main.cpp)

target_link_libraries(reverse_integer PUBLIC solution_class)
