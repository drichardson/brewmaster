#include "DDException.h"
#include <stdio.h>
#include <stdarg.h>

// Logs and exception and aborts.
void COException(const char* msg, ...)
{
	va_list v;
	va_start(v, msg);
	vfprintf(stderr, msg, v);
	fputc('\n', stderr);
	va_end(v);
}
