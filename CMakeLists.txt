cmake_minimum_required(VERSION 4.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_UNITY_BUILD OFF)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 32)
set(CMAKE_CONFIGURATION_TYPES Debug Release RelWithDebInfo MinSizeRel)

# set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
# set(CMAKE_SKIP_INSTALL_RPATH OFF)
# set(CMAKE_SKIP_BUILD_RPATH OFF)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(
    sdl-vulkan-learn
    VERSION 0.0.4.0
    DESCRIPTION "blah blah blah"
    HOMEPAGE_URL "http://localhost"
    LANGUAGES C CXX
)

if(NOT 23 IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    message(
        FATAL_ERROR
        "For build this project needed cxx23 support or higher. Install clang 19+ and newer libc++ or gcc 15+"
    )
endif()

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(functions REQUIRED)
find_package(options REQUIRED)
find_package(compiler REQUIRED)

svl_setup_global_compiler()

configure_file(
    ${CMAKE_SOURCE_DIR}/src/svl_config.hxx.in
    ${CMAKE_BINARY_DIR}/svl_config.hxx
    @ONLY
)

add_library(svl_base INTERFACE)
# use logging in all libs
target_link_libraries(svl_base INTERFACE spdlog::spdlog libassert::assert)
target_compile_definitions(
    svl_base
    INTERFACE $<$<CONFIG:Debug>:SVL_DEBUG> $<$<PLATFORM_ID:Linux>:SVL_LINUX>
)
target_include_directories(
    svl_base
    INTERFACE ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/src
) # svl_config.hxx
svl_setup_target_compiler(svl_base)
add_library(svl::base ALIAS svl_base)

add_subdirectory(external)

# skip analyze external libs
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_subdirectory(src)
add_subdirectory(example)

include(CTest)
add_subdirectory(tests)

set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_VERBATIM_VARIABLES ON)
set(CPACK_THREADS 4)

set(CPACK_PACKAGE_ICON ${CMAKE_SOURCE_DIR}/src/svl.png)
include(CPack)
