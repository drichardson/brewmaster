# minimum version of cmake required
cmake_minimum_required(VERSION 2.8.10.2)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process --output-on-failure)

# project name
project(objects)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

include_directories(include)

add_library(objects STATIC include/class.h src/class.c include/DDObjectBase.h src/DDObjectBase.c include/DDOBjectDefinition.h src/DDObjectDefinition.c include/DDException.h src/DDException.c)

add_executable(unittest src/unittest.c)
target_link_libraries(unittest objects)

enable_testing()
set(CTEST_OUTPUT_ON_FAILURE TRUE)
add_test(quicklook unittest)
