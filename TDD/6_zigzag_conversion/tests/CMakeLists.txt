cmake_minimum_required(VERSION 3.15...3.21)
project(longest_substring)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/750d67d809700ae8fca6d610f7b41b71aa161808.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  solution_test
  ../solution.cpp
  solution_test.cpp
)
target_link_libraries(
  solution_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(solution_test)
