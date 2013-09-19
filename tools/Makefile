TARGETS=fontinfo
CFLAGS=-g -O0

fontinfo: fontinfo.c
	$(CC) -o $@ $^ $(CFLAGS) -I/usr/include/freetype2 -lfreetype

clean:
	$(RM) $(TARGETS)

