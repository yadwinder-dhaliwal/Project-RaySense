#include "raysense/lidar.hpp"

namespace raysense {

std::uint32_t columns_per_revolution(const LidarConfig& config)
{
    // TODO(you): how many azimuth steps fit in 360 degrees?
    //   Hint: watch out for floating-point error. 360.0f / 0.2f is not exactly 1800.
    (void)config;
    return 0;
}

std::vector<Vec3> generate_scan_directions(const LidarConfig& config)
{
    // TODO(you): implement the scan pattern described in include/raysense/lidar.hpp.
    //
    // Suggested steps:
    //   1. Work out the number of columns and reserve space in the vector.
    //   2. Work out the elevation step between channels (careful with channels == 1).
    //   3. For each column, for each channel:
    //        azimuth   = column  * horizontal resolution
    //        elevation = min fov + channel * elevation step
    //      convert degrees to radians, then spherical -> Cartesian:
    //        x = cos(elevation) * cos(azimuth)
    //        y = cos(elevation) * sin(azimuth)
    //        z = sin(elevation)
    //
    // Run the tests (ctest --preset debug) until they all pass.
    (void)config;
    return {};
}

} // namespace raysense
