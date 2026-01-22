add_subdirectory(utils)
add_subdirectory(core)
add_subdirectory(platform)
add_subdirectory(renderer)

add_library(svl SHARED)
target_sources(svl PUBLIC FILE_SET svl_module TYPE CXX_MODULES FILES svl.cxxm)
target_link_libraries(
    svl
    PRIVATE svl::base
    PUBLIC svl::platform svl::core svl::renderer
)

add_library(svl::svl ALIAS svl)
