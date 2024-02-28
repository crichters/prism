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

while(!get_window_close_flag(prism_window)) {
//        process_input(prism_window);

//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);

//        invoke_swap_chain(prism_window);
        poll_window_events(prism_window);
    }

    terminate_window_engine();
    return 0;
}


