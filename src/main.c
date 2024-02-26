// System Includes
#include <stdio.h>
#include <stdarg.h>

// Local Lib Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <prism_util.h>

#include <window_api.h>

int main(int argc, char *argv[])
{

    struct PrismWindow prism_window;

    initialize_window_engine();

    int success = create_prism_window(800, 600, "Test Window", &prism_window);

    if(success != 0) {
        return -1;
    }

    terminate_window_engine();
    return 0;
}


