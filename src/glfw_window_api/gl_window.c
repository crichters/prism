#include<window_api.h>
#include<prism_util.h>
#include <glfw_gl_window_api.h>


// Invoke Swap Chain
// TODO: Read up more on Vulkan swap chains? Idk man 
void invoke_swap_chain(struct PrismWindow prism_window) {
    GLFWwindow *window = prism_window.window_ptr;
    glfwSwapBuffers(window);
}

// Poll window or windowing system for events
// TODO: Refine this when learning if quering events is commonly done on a per-window basis 
void poll_window_events(struct PrismWindow prism_window) {
    glfwPollEvents();
}

int get_window_close_flag(struct PrismWindow prism_window) {
    GLFWwindow *window = prism_window.window_ptr;

    return glfwWindowShouldClose(window);
}

void process_input(struct PrismWindow prism_window) {
    GLFWwindow *window = prism_window.window_ptr; 
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

void initialize_window_engine() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void terminate_window_engine() {
    glfwTerminate();
}

int create_prism_window(
        int width, int height, 
        const char *window_hint, 
        struct PrismWindow  *prism_window
        ) {

    GLFWwindow *window = glfwCreateWindow(width, height, window_hint, NULL, NULL);
    
    if (window == NULL) {
        log_error("Error: Failed to create GLFW Window\n");
        terminate_window_engine();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        log_error("Error: failed to initialize GLAD\n");
        return -1;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    prism_window->window_ptr = window;
    prism_window->width = width;
    prism_window->height = height;

    return 0;
}


void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
