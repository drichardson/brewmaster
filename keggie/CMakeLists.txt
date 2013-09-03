# minimum version of cmake required
cmake_minimum_required(VERSION 2.8.9)

# project name
project(keggie)

set(CMAKE_BUILD_TYPE Debug)

# When I use clang, the assembler gives me a warning like this:
# /tmp/main-dZdoda.s:419: Rd and Rm should be different in mul
# This happens even if I set -march=armv6 or -mcpu=<blah> where
# <blah> is try a bunch of different things the Internet suggests.
# It still seems to work, mind you, but I'm going to use gcc for now
# until I really need clang, for peace of mind.
# set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

include_directories(. /opt/vc/include/ /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)
link_directories(/opt/vc/lib)

add_executable(keggie main.c texture_loader.c)
target_link_libraries(keggie GLESv2 EGL bcm_host png)

