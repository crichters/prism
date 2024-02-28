#ifndef GLFW_VULKAN_API_H
#define GLFW_VULKAN_API_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <prism_util.h>

#include <vulkan_management.h>

struct VulkanConfig {
    VkInstance instance;
};

void init_glfw();
void init_vulkan();

struct VulkanConfig vulkan_config;

#endif // !GLFW_VULKAN_API_H
