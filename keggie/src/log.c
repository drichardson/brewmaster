#include "log.h"
#include <stdio.h>

static void default_handler(log_level_t level, char const* format, va_list va) {
    vprintf(format, va);
    putchar('\n');
}

static void (*_log_handler)(log_level_t, char const*, va_list) = default_handler;

void log_register_handler(void (*handler)(log_level_t level, char const*, va_list)) {
    _log_handler = handler;
}

void log_messagev_with_level(log_level_t level, char const* format, va_list va) {
    _log_handler(level, format, va);
}

void log_debug(char const* format, ...) {
    va_list va;
    va_start(va, format);
    _log_handler(LOG_LEVEL_DEBUG, format, va);
    va_end(va);
}

void log_error(char const* format, ...) {
    va_list va;
    va_start(va, format);
    _log_handler(LOG_LEVEL_ERROR, format, va);
    va_end(va);
}

