list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/Catch2/extras)

add_executable(tests-render)

file(
    GLOB_RECURSE resoures
    LIST_DIRECTORIES OFF
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/res"
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/res/*"
)
target_sources(tests-render PRIVATE renderer/shader_compile.cxx)

target_link_libraries(
    tests-render
    PRIVATE svl::svl svl::base Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(tests-render)

svl_add_resources(
    USE_SYMLINKS
    TARGET tests-render
    DESTINATION .
    FOLDERS ${CMAKE_CURRENT_LIST_DIR}/res
)
install(
    TARGETS tests-render
    RUNTIME_DEPENDENCY_SET deps
    RUNTIME DESTINATION tests
)
install(
    RUNTIME_DEPENDENCY_SET
    deps
    PRE_EXCLUDE_REGEXES
        [[libc\.so\..*]]
        [[libgcc_s\.so\..*]]
        [[libm\.so\..*]]
        [[libstdc\+\+\.so\..*]]
)
