cmake_minimum_required(VERSION 3.10)

project(Matrix++ VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_BUILD_TYPE Release)

if(CMAKE_BUILD_TYPE EQUAL "Debug")
  add_compile_options(-fsanitize=address)
  add_link_options(-fsanitize=address)
endif()

add_library(s21_matrix_oop STATIC s21_matrix_oop.cpp)
target_compile_options(s21_matrix_oop PRIVATE -Wall -Werror -Wextra -Wpedantic)

find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

file(GLOB SOURCES ./tests/*.cpp)
add_executable(tests ${SOURCES})
target_compile_options(tests PRIVATE -Wall -Werror -Wextra -Wpedantic)

target_link_libraries(tests GTest::gtest_main s21_matrix_oop)

gtest_discover_tests(tests)
