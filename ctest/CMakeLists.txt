# Minimum CMake version
cmake_minimum_required(VERSION 3.21)

# Define version
set(VER_MAJOR 0)
set(VER_MINOR 1)
set(VER_PATCH 0)

# Setup project
project(triangle
    VERSION "${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}"
    DESCRIPTION "Find type of triangle based on side lengths"
    LANGUAGES C
    )

# Set C standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Standard installation paths
include(GNUInstallDirs)

# Default build in release mode
# Can be overridden with: cmake -DCMAKE_BUILD_TYPE=Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Default install to source directory
if(NOT CMAKE_INSTALL_BINDIR)
    set(CMAKE_INSTALL_BINDIR "${CMAKE_SOURCE_DIR}")
endif()

# Build subcommands
add_subdirectory(src)

if(NOT RUN_TESTS)
    set(RUN_TESTS true)
endif()

if(RUN_TESTS)
    include(CTest)

    add_subdirectory(test)
endif()
