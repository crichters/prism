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

//void init_vulkan() {
//    VkApplicationInfo app_info = {};
//    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//    app_info.pApplicationName = "Hello Triangle";
//    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//    app_info.pEngineName = "No Engine";
//    app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//    app_info.apiVersion = VK_API_VERSION_1_0;
//
//    VkInstanceCreateInfo create_info = {};
//    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//    create_info.pApplicationInfo = &app_info;
//
//    uint32_t glfw_extension_count = 0;
//    
//    // Watch for Mem Safety
//    const char** glfw_extensions;
//
//    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
//
//    create_info.enabledExtensionCount = glfw_extension_count;
//    create_info.ppEnabledExtensionNames = glfw_extensions;
//    create_info.enabledLayerCount = 0;
//    
//    VkResult result = vkCreateInstance(&create_info, NULL, &vulkan_instance);
//
//    if(result != VK_SUCCESS) {
//        log_error("Error, unable to initialize Vulkan Instance\n");
//    }
//}

void initialize_window_engine() {
   init_glfw();
   int vk_instance_success = create_vk_instance(&vulkan_config.instance);
//   init_vulkan();
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
