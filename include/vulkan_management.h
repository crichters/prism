#include<vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include<prism_util.h>

int create_vk_instance(VkInstance *vulkan_instance);

VkPhysicalDevice pick_vk_physical_device();


