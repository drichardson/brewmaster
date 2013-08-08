# minimum version of cmake required
cmake_minimum_required(VERSION 2.8.10.2)

# project name
project(objects)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_library(objects STATIC DDObjectBase.c DDObjectDefinition.c DDException.c)

add_executable(unittest unittest.c)

enable_testing()
add_test(quicklook unittest)
