set(SDL_STATIC OFF)
set(SDL_SHARED ON)
set(SDL_TESTS OFF)
set(SDL_WAYLAND ${SVL_WAYLAND})
set(SDL_X11 ${SVL_X11})
set(SDL_DISABLE_INSTALL ON)
add_subdirectory(SDL EXCLUDE_FROM_ALL SYSTEM)

# Use our built of SPIRV-Tools instead system, for avoid
# stdlib mismatch
add_subdirectory(SPIRV-Headers EXCLUDE_FROM_ALL SYSTEM)
set(SPIRV_SKIP_EXECUTABLES ON)
set(SPIRV_SKIP_TESTS ON)
add_subdirectory(SPIRV-Tools EXCLUDE_FROM_ALL SYSTEM)

set(ALLOW_EXTERNAL_SPIRV_TOOLS ON)
set(GLSLANG_TESTS OFF)
set(ENABLE_GLSLANG_BINARIES OFF)
add_subdirectory(glslang EXCLUDE_FROM_ALL SYSTEM)

add_subdirectory(Vulkan-Headers EXCLUDE_FROM_ALL SYSTEM)

set(VOLK_NAMESPACE ON)
set(VOLK_STATIC_DEFINES)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    if(SVL_X11)
        list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_XCB_KHR)
    endif()
    if(SVL_WAYLAND)
        list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_WAYLAND_KHR)
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_WIN32_KHR)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Android")
    list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_ANDROID_KHR)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_MACOS_MVK)
elseif(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    list(APPEND VOLK_STATIC_DEFINES VK_USE_PLATFORM_IOS_MVK)
endif()
add_subdirectory(volk)
# Hack for find vulkan header
target_link_libraries(volk PRIVATE Vulkan::Headers)

# ios support https://github.com/gabime/spdlog/issues/2884
add_subdirectory(spdlog EXCLUDE_FROM_ALL SYSTEM)

add_subdirectory(Catch2 EXCLUDE_FROM_ALL SYSTEM)
add_subdirectory(argparse EXCLUDE_FROM_ALL SYSTEM)

# Small hack for use clang libunwind instead gnu unwind inside libassert.
set(CPPTRACE_UNWIND_WITH_LIBUNWIND ON)
add_subdirectory(libassert EXCLUDE_FROM_ALL SYSTEM)

set(KTX_FEATURE_TESTS OFF)
set(KTX_FEATURE_TOOLS OFF)
add_subdirectory(KTX-Software EXCLUDE_FROM_ALL SYSTEM)
add_library(KTX::ktx ALIAS ktx)
