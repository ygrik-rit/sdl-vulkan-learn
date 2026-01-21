add_library(window STATIC)

target_sources(
    window
    PUBLIC FILE_SET window_module TYPE CXX_MODULES FILES window.cxxm
)
target_link_libraries(
    window
    PRIVATE svl::base SDL3::SDL3-shared Vulkan::HppModule
)
add_library(svl::window ALIAS window)
