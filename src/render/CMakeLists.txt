add_library(render OBJECT)

target_sources(
    render
    PUBLIC FILE_SET window_module TYPE CXX_MODULES FILES render.cxxm
    PRIVATE render.cxx
)

target_link_libraries(render PRIVATE SDL3::SDL3-shared svl::base)

add_library(svl::render ALIAS render)
