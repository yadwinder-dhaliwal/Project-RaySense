cmake_minimum_required(VERSION 3.25)

project(RaySense
    VERSION 0.1.0
    DESCRIPTION "GPU-accelerated LiDAR and camera sensor simulator"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(RAYSENSE_BUILD_APP   "Build the Vulkan viewer app (needs a GPU, Vulkan SDK, GLFW)" ON)
option(RAYSENSE_BUILD_TESTS "Build unit tests" ON)

# Shared warning flags for every RaySense target
add_library(raysense_warnings INTERFACE)
target_compile_options(raysense_warnings INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Wshadow -Wconversion>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->)

add_subdirectory(src/core)

if(RAYSENSE_BUILD_APP)
    add_subdirectory(src/app)
endif()

if(RAYSENSE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
