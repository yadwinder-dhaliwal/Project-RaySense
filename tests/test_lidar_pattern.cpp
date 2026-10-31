// Tests for the LiDAR scan pattern. These fail until you implement
// src/core/lidar_pattern.cpp. Run with:  ctest --preset debug
//
// Deliberately framework-free so there's nothing extra to install.
// Feel free to switch to Catch2 or GoogleTest later (add it to vcpkg.json).

#include "raysense/lidar.hpp"

#include <cmath>
#include <cstdio>
#include <numbers>

namespace {

int g_failures = 0;

#define CHECK(cond)                                                       \
    do {                                                                  \
        if (!(cond)) {                                                    \
            std::printf("FAIL %s:%d  %s\n", __FILE__, __LINE__, #cond);   \
            ++g_failures;                                                 \
        }                                                                 \
    } while (0)

bool near(float a, float b, float eps = 1e-4f) { return std::fabs(a - b) < eps; }

float deg2rad(float d) { return d * std::numbers::pi_v<float> / 180.0f; }

raysense::LidarConfig test_config()
{
    raysense::LidarConfig c;
    c.channels = 16;
    c.vertical_fov_min_deg = -15.0f;
    c.vertical_fov_max_deg = 15.0f;
    c.horizontal_resolution_deg = 1.0f;
    return c;
}

void test_columns()
{
    raysense::LidarConfig c = test_config();
    CHECK(raysense::columns_per_revolution(c) == 360);

    c.horizontal_resolution_deg = 0.2f; // 360 / 0.2 is not exact in float
    CHECK(raysense::columns_per_revolution(c) == 1800);
}

void test_ray_count()
{
    const auto c = test_config();
    const auto dirs = raysense::generate_scan_directions(c);
    CHECK(dirs.size() == 360u * 16u);
}

void test_unit_length()
{
    const auto dirs = raysense::generate_scan_directions(test_config());
    for (const auto& d : dirs) {
        const float len = std::sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
        if (!near(len, 1.0f)) {
            CHECK(near(len, 1.0f));
            return; // one failure message is enough
        }
    }
}

void test_known_directions()
{
    const auto c = test_config();
    const auto dirs = raysense::generate_scan_directions(c);
    if (dirs.size() != 360u * 16u) {
        CHECK(!"wrong ray count, skipping direction checks");
        return;
    }
    const float e = deg2rad(15.0f);

    // Column 0, lowest beam: straight ahead, tilted 15 deg down.
    const auto& first = dirs[0];
    CHECK(near(first.x, std::cos(e)));
    CHECK(near(first.y, 0.0f));
    CHECK(near(first.z, -std::sin(e)));

    // Column 0, highest beam: straight ahead, tilted 15 deg up.
    const auto& top = dirs[15];
    CHECK(near(top.x, std::cos(e)));
    CHECK(near(top.z, std::sin(e)));

    // Column 90 (azimuth 90 deg), lowest beam: pointing left (+y).
    const auto& left = dirs[90 * 16];
    CHECK(near(left.x, 0.0f));
    CHECK(near(left.y, std::cos(e)));
    CHECK(near(left.z, -std::sin(e)));
}

} // namespace

int main()
{
    test_columns();
    test_ray_count();
    test_unit_length();
    test_known_directions();

    if (g_failures == 0) {
        std::printf("All LiDAR pattern tests passed.\n");
        return 0;
    }
    std::printf("%d check(s) failed.\n", g_failures);
    return 1;
}
