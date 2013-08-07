TARGETS=gcd framebuffer_info
CFLAGS=-g -O0 -Wall -Werror
CC=clang

all: $(TARGETS)

gcd: gcd.c
	$(CC) -fblocks -lBlocksRuntime -ldispatch $< $(CFLAGS) -o $@

framebuffer_info: framebuffer_info.c
	$(CC) $< $(CFLAGS) -o $@

clean:
	$(RM) $(TARGETS)
