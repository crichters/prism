// System Includes
#include <stdio.h>
#include <stdarg.h>

// Local Lib Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Error Logging function, 
// prints to stderr
void log_error(const char *format, ...) {
    
    va_list args;

    va_start(args, format);

    vfprintf(stderr, format, args);

    va_end(args);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main(int argc, char *argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 800, "Test Window", NULL, NULL);

    if (window == NULL) {
        log_error("Error: Failed to create GLFW Window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        log_error("Error: failed to initialize GLAD\n");
        return -1;
    }

    glViewport(0, 0, 800, 800);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
