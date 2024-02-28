#include <prism_util.h>

// Error Logging function, 
// prints to stderr
void log_error(const char *format, ...) {
    
    va_list args;

    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
}


int file_to_string(const char *filename, char *buffer) {
    int success = -1;
    long length;

    FILE *f = fopen(filename, "rb");
    
    if(!f) {
        log_error("Error: unable to open file: %s\n", filename);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = malloc(length);

    if(!buffer) {
        log_error("Error: unable to allocate memory for file: %s\n", filename);
        return -1;
    }
    
    fread(buffer, 1, length, f);
    fclose(f);

    return 0;
}
