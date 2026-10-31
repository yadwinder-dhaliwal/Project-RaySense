# raysense_core: CPU-side sensor models. No GPU or third-party deps, so it builds in CI.
add_library(raysense_core
    lidar_pattern.cpp)

target_include_directories(raysense_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(raysense_core PUBLIC cxx_std_20)
target_link_libraries(raysense_core PRIVATE raysense_warnings)
