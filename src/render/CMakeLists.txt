add_subdirectory(utils)

add_library(render STATIC)

target_sources(
    render
    PUBLIC FILE_SET render_module TYPE CXX_MODULES FILES render.cxxm
)

target_link_libraries(render PRIVATE SDL3::SDL3-shared svl::base)

add_library(svl::render ALIAS render)
