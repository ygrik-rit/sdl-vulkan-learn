add_library(utils STATIC)

target_sources(
    utils
    PUBLIC FILE_SET utils_module TYPE CXX_MODULES FILES vulkan_extension.cxxm
)

target_link_libraries(utils PRIVATE svl::base)

add_library(svl::utils ALIAS utils)
