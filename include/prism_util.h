#ifndef PRISM_UTIL_H
#define PRISM_UTIL_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void log_error(const char *format, ...);

int file_to_string(const char *filename, char *buffer);

#endif // UTIL_H
