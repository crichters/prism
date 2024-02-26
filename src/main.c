#include <stdio.h>
#include <stdarg.h>


// Error Logging function, 
// prints to stderr
void log_error(const char *format, ...) {
    
    va_list args;

    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
}

int main(int argc, char *argv[])
{
    
    log_error("Caught test error #%d\n", 5);
    printf("Test\n");
    return 0;

}
