# RaySense

GPU-accelerated LiDAR and camera sensor simulator in C++20/Vulkan. RaySense ray-traces 3D scenes on RTX hardware and produces synthetic point clouds and images, so robotics and autonomy perception software can be tested without physical sensors.

> **Status:** early development (milestone M0: build setup and Vulkan bootstrap).

## Planned features

- Configurable spinning LiDAR (channels, vertical FOV, resolution, range, noise)
- Hardware ray tracing via Vulkan (`VK_KHR_acceleration_structure`, `VK_KHR_ray_query`)
- OpenUSD scene loading
- Pinhole camera output
- ROS 2 streaming (`sensor_msgs/PointCloud2`, `sensor_msgs/Image`) for RViz and perception stacks

## Roadmap

| Milestone | Goal | Target |
|---|---|---|
| M0 | Build setup, Vulkan window + ImGui on the GPU | Nov 2026 |
| M1 | LiDAR scan pattern, ray-query against a test scene | |
| M2 | OpenUSD scene loading | |
| M3 | Noise, intensity and sensor realism | |
| M4 | ROS 2 bridge | |
| M5 | Camera sensor | |
| M6 | Performance pass, docs and demo video | Mar 2027 |

## Building

Requirements: Linux (developed on Ubuntu 24.04), a GPU with Vulkan ray tracing support, GCC 13+ or Clang 17+, CMake 3.25+, Ninja, the [LunarG Vulkan SDK](https://vulkan.lunarg.com) and [vcpkg](https://github.com/microsoft/vcpkg) with `VCPKG_ROOT` set.

```bash
cmake --preset debug          # first run downloads dependencies via vcpkg
cmake --build --preset debug
ctest --preset debug          # unit tests
./build/debug/src/app/raysense
```

No GPU? `cmake --preset ci` builds just the CPU core and tests.

## Project layout

```
include/raysense/   public headers
src/core/           CPU-side sensor models (no GPU deps)
src/app/            Vulkan viewer application
shaders/            GLSL shaders
scenes/             test scenes
tests/              unit tests
docs/               design notes
```

## Coordinate convention

Follows [ROS REP 103](https://www.ros.org/reps/rep-0103.html): +x forward, +y left, +z up.

## License

MIT. See [LICENSE](LICENSE).
