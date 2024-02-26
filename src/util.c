#include <prism_util.h>

// Error Logging function, 
// prints to stderr
void log_error(const char *format, ...) {
    
    va_list args;

    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
}

