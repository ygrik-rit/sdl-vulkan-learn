add_library(renderer STATIC)

target_sources(
    renderer
    PUBLIC
        FILE_SET renderer_module
        TYPE CXX_MODULES
        FILES queue/command_manager.cxxm renderer.cxxm
)
target_link_libraries(renderer PRIVATE svl::utils Vulkan::HppModule)
add_library(svl::renderer ALIAS renderer)
