TARGETS=gcd framebuffer_info framebuffer_draw
CFLAGS=-g -O0 -Wall -Werror
CC=clang

all: $(TARGETS)

gcd: gcd.c
	$(CC) -fblocks -lBlocksRuntime -ldispatch $< $(CFLAGS) -o $@

framebuffer_info: framebuffer_info.c
	$(CC) $< $(CFLAGS) -o $@

framebuffer_draw: framebuffer_draw.c
	$(CC) $< $(CFLAGS) -o $@

clean:
	$(RM) $(TARGETS)
