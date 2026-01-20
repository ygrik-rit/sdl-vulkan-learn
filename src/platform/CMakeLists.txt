add_subdirectory(window)

add_library(platform OBJECT)

target_sources(
    platform
    PUBLIC FILE_SET platform_module TYPE CXX_MODULES FILES platform.cxxm
)
target_link_libraries(platform PRIVATE svl::window)

add_library(svl::platform ALIAS platform)
