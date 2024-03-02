#include <window_api.h>
#include <glfw_vulkan_window_api.h>

void init_glfw() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

// Create prism window
int create_prism_window(
        int width, 
        int height, 
        const char *window_hint, 
        struct PrismWindow *prism_window
        ) {


    GLFWwindow *window = glfwCreateWindow(width, height, window_hint, NULL, NULL);
    
    if (window == NULL) {
        log_error("Error: Failed to create GLFW Window\n");
        terminate_window_engine();
        return -1;
    }

    prism_window->width = width;
    prism_window->height = height;
    prism_window->window_ptr = window;

    return 0;
}


void initialize_window_engine() {
    init_glfw();
    init_vulkan(vulkan_config);
}

void init_vulkan(struct VulkanConfig vk_config) {
    int vk_instance_success = create_vk_instance(&vk_config.instance);

    if(0 != vk_instance_success) {
        return;
    }

    int vk_physical_success = create_vk_physical_device(
        &vk_config.physical_device, 
        vk_config.instance
    );

    if(0 != vk_physical_success) {
        return;
    }
}


void terminate_window_engine() {
    vkDestroyInstance(vulkan_config.instance, NULL);
    glfwTerminate();
}

int get_window_close_flag(struct PrismWindow prism_window) {
    return glfwWindowShouldClose(prism_window.window_ptr);
}

void poll_window_events(struct PrismWindow prism_window) {
    glfwPollEvents();
}
