#pragma once

#include <stdarg.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR
} log_level_t;

//
// Core functions
//

// Set the log handler. Defaults to standard output.
void log_register_handler(void (*)(log_level_t level, char const*, va_list));

// Low level logging function. Convenience functions built on this.
void log_messagev_with_level(log_level_t level, char const* format, va_list va);

//
// Convenience functions
//
void log_debug(char const* format, ...) __attribute__((format (printf, 1, 2))); 
void log_error(char const* format, ...) __attribute__((format (printf, 1, 2)));
