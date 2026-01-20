add_library(window STATIC)

target_sources(
    window
    PRIVATE
        FILE_SET headers
        TYPE HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src/
        FILES window.hxx
    PRIVATE window.cxx
)
target_link_libraries(window PRIVATE svl::base SDL3::SDL3-shared)
add_library(svl::window ALIAS window)
