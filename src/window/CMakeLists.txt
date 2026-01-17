add_library(window STATIC)

add_subdirectory(device)

target_sources(
    window
    PUBLIC FILE_SET window_module TYPE CXX_MODULES FILES window.cxxm
    PRIVATE window.cxx
)
target_link_libraries(window PRIVATE SDL3::SDL3-shared svl::device svl::base)
add_library(svl::window ALIAS window)
