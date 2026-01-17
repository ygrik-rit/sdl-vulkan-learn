cmake_minimum_required(VERSION 3.31.6 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD 1)

# Global use mold linker
add_link_options(-fuse-ld=mold)

project(
    sdl-vulkan-learn
    VERSION 0.0.1.0
    DESCRIPTION "blah blah blah"
    HOMEPAGE_URL "http://localhost"
    LANGUAGES C CXX
)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(options REQUIRED)

configure_file(
    ${CMAKE_SOURCE_DIR}/src/svl_config.hxx.in
    ${CMAKE_BINARY_DIR}/svl_config.hxx
    @ONLY
)

add_library(svl_base INTERFACE)
target_compile_definitions(
    svl_base
    INTERFACE $<$<CONFIG:Debug>:SVL_DEBUG> $<$<PLATFORM_ID:Linux>:SVL_LINUX>
)
target_compile_options(svl_base INTERFACE -Werror -Wpedantic -Wall)
target_include_directories(svl_base INTERFACE ${CMAKE_BINARY_DIR}) # svl_config.hxx
add_library(svl::base ALIAS svl_base)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(example)
