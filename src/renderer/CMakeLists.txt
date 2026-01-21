add_library(renderer INTERFACE)

# target_sources(
#     renderer
#     PUBLIC FILE_SET renderer_module TYPE CXX_MODULES FILES utils/utils.cxxm
# )

add_library(svl::renderer ALIAS renderer)
