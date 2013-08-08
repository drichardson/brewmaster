objects
-------
Object system in C. Supports reference counting, single inheritance, exceptions, and autorelease pools.

build
-----
The build system uses cmake. There is a top level Makefile that wraps the cmake commands
for convenience, but you are free to use cmake directly as well.
* make all - builds for the current platform using standard Makefiles
* make xcode - builds an Xcode project that can be used to build

