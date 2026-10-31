// RaySense viewer entry point.
//
// Milestone M0 (due Nov 8): a GLFW window running Vulkan on the RTX 5070,
// with an ImGui panel. Work through the TODOs in order; each one should
// compile and run before you move to the next.
//
// Main reference: https://vkguide.dev  (chapters 0-2 cover most of M0)
// Spec lookup:    https://registry.khronos.org/vulkan/specs/latest/html/

// Tell GLFW to include vulkan.h and skip the OpenGL headers.
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdio>

int main()
{
    // TODO 1: Initialise GLFW and create a window (GLFW_NO_API, since we use Vulkan).
    //         Loop until the window is closed, calling glfwPollEvents().

    // TODO 2: Create a VkInstance with the validation layer
    //         (VK_LAYER_KHRONOS_validation) enabled in debug builds,
    //         plus the instance extensions GLFW needs
    //         (glfwGetRequiredInstanceExtensions).

    // TODO 3: Enumerate physical devices, print each one's name, and pick
    //         the discrete GPU that supports:
    //           VK_KHR_acceleration_structure
    //           VK_KHR_ray_query
    //           VK_KHR_deferred_host_operations (required by acceleration_structure)
    //         Your machine reports two devices, so this check matters.

    // TODO 4: Create a VkSurfaceKHR (glfwCreateWindowSurface), a logical
    //         device with a graphics+present queue, and a swapchain.

    // TODO 5: Each frame, acquire a swapchain image, clear it to a colour,
    //         and present it. (Your first visible Vulkan output.)

    // TODO 6: Initialise Dear ImGui (imgui_impl_glfw + imgui_impl_vulkan)
    //         and draw a panel showing the GPU name and frame time.
    //         -> M0 done.

    // TODO 7: Clean up everything in reverse order of creation.

    std::printf("RaySense: nothing here yet. Start with TODO 1 in src/app/main.cpp\n");
    return 0;
}
