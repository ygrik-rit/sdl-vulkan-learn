add_library(device STATIC)

target_sources(
    device
    PUBLIC FILE_SET device_module TYPE CXX_MODULES FILES device.cxxm gpu.cxxm
)
target_link_libraries(
    device
    PRIVATE svl::base svl::utils SDL3::SDL3-shared Vulkan::HppModule
)
add_library(svl::device ALIAS device)
