find_package(Vulkan REQUIRED)            # from the LunarG Vulkan SDK
find_package(glfw3 CONFIG REQUIRED)      # from vcpkg
find_package(glm CONFIG REQUIRED)        # from vcpkg
find_package(imgui CONFIG REQUIRED)      # from vcpkg

add_executable(raysense main.cpp)

target_link_libraries(raysense PRIVATE
    raysense_core
    raysense_warnings
    Vulkan::Vulkan
    glfw
    glm::glm
    imgui::imgui)
