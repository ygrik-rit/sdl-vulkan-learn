add_library(utils OBJECT)

target_sources(
    utils
    PUBLIC FILE_SET utils_module TYPE CXX_MODULES FILES result_check.cxxm
)
target_link_libraries(
    utils
    PRIVATE svl::base Vulkan::HppModule SDL3::SDL3-shared spdlog::spdlog
)

add_library(svl::utils ALIAS utils)
