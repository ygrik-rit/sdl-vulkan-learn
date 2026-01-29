list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/Catch2/extras)

include(CTest)
include(Catch)

add_executable(tests-render)

target_sources(tests-render PRIVATE renderer/shader_compile.cxx)
target_link_libraries(
    tests-render
    PRIVATE svl::svl svl::base Catch2::Catch2WithMain
)

catch_discover_tests(tests-render)
