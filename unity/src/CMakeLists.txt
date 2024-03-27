# Minimum CMake version
cmake_minimum_required(VERSION 3.21)

# Source and header files
file(GLOB sources *.c)
file(GLOB headers *.h)

# triangle.c is what executable is compiled from
list(REMOVE_ITEM sources triangle.c)

# Build triangle executable
add_executable(triangle triangle.c)
