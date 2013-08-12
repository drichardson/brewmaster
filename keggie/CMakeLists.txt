# minimum version of cmake required
cmake_minimum_required(VERSION 2.8.9)

# project name
project(keggie)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

include_directories(/opt/vc/include/ /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)
link_directories(/opt/vc/lib)

add_executable(keggie main.c tiger.c)
target_link_libraries(keggie OpenVG EGL GLESv2 bcm_host)

