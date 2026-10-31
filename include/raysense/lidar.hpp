#pragma once

#include <cstdint>
#include <vector>

namespace raysense {

// Simple 3D vector. Coordinate convention follows ROS REP 103:
//   +x = forward, +y = left, +z = up.
struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

// Parameters of a spinning (mechanical) LiDAR, e.g. a Velodyne/Ouster-style sensor.
struct LidarConfig {
    std::uint32_t channels = 32;            // number of vertical beams (lasers)
    float vertical_fov_min_deg = -15.0f;    // elevation of the lowest beam
    float vertical_fov_max_deg = 15.0f;     // elevation of the highest beam
    float horizontal_resolution_deg = 0.2f; // azimuth step between firings
    float min_range_m = 0.5f;
    float max_range_m = 100.0f;
    float rotation_hz = 10.0f;              // full revolutions per second
};

// Number of azimuth steps (columns) in one full 360-degree revolution.
// Example: 0.2 deg resolution -> 1800 columns.
std::uint32_t columns_per_revolution(const LidarConfig& config);

// Generate the unit direction of every ray fired in one full revolution.
//
// Layout (column-major), so the tests and later the GPU code agree:
//   index = column * channels + channel
//   column 0 is azimuth 0 deg (+x), azimuth increases counter-clockwise
//   (toward +y) by horizontal_resolution_deg per column.
//   channel 0 is the lowest beam (vertical_fov_min_deg), the last channel is
//   the highest (vertical_fov_max_deg), with beams evenly spaced in between.
//
// Every returned vector must have length 1.
std::vector<Vec3> generate_scan_directions(const LidarConfig& config);

} // namespace raysense
