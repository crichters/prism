#ifndef GLFW_VULKAN_API_H
#define GLFW_VULKAN_API_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <prism_util.h>

void init_glfw();
void init_vulkan();

VkInstance vulkan_instance;

#endif // !GLFW_VULKAN_API_H
