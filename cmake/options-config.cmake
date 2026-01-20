include(CMakeDependentOption)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(is_linux ON)
endif()

option(
    SVL_DEBUG_3RDPARTY
    "Force build 3rdparty libs localy for comfortable debugging"
    OFF
)

cmake_dependent_option(
    SVL_WAYLAND
    "Built with support Wayland"
    ON
    is_linux
    OFF
)
cmake_dependent_option(
    SVL_X11
    "Built with support X11"
    OFF
    is_linux
    OFF
)
