# Minimum CMake version
cmake_minimum_required(VERSION 3.21)

# Need to create a core library that gets linked with executables
add_library(core triangle.c triangle.h)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
