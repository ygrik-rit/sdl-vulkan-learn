add_library(renderer_utils STATIC)

target_sources(
    renderer_utils
    PUBLIC FILE_SET renderer_module TYPE CXX_MODULES FILES utils.cxxm
)
target_link_libraries(renderer_utils PRIVATE svl::base)

add_library(svl::renderer::utils ALIAS renderer_utils)
