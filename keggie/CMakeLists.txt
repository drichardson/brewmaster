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
set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

set(RASPI_INCLUDES /opt/vc/include/ /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)

include_directories(/usr/include/freetype2 ${RASPI_INCLUDES})
link_directories(/opt/vc/lib)

# Build the application bundle
set(KEGGIE_BUNDLE_PATH ${CMAKE_BINARY_DIR}/keggie.app)
file(MAKE_DIRECTORY ${KEGGIE_BUNDLE_PATH})
file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${KEGGIE_BUNDLE_PATH})
file(COPY ${CMAKE_SOURCE_DIR}/fonts DESTINATION ${KEGGIE_BUNDLE_PATH})
file(COPY ${CMAKE_SOURCE_DIR}/images DESTINATION ${KEGGIE_BUNDLE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${KEGGIE_BUNDLE_PATH})
add_executable(keggie src/main.c src/texture_loader.c src/shader_loader.c src/egl_context.c src/gl_context.c src/text_rendering.c src/log.c src/bundle.c src/image.c src/png_reader.c src/jpeg_reader.c src/paths.c src/matrix.c)
target_link_libraries(keggie GLESv2 EGL bcm_host png jpeg freetype)

