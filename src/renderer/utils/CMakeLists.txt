add_library(renderer_utils OBJECT)

target_sources(
    renderer_utils
    PUBLIC
        FILE_SET renderer_module
            TYPE CXX_MODULES
            FILES texture/texture.cxxm utils.cxxm
)
target_link_libraries(
    renderer_utils
    PRIVATE svl::base KTX::ktx Vulkan::HppModule
)

add_library(svl::renderer::utils ALIAS renderer_utils)
