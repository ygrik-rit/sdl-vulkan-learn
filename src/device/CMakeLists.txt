add_library(device STATIC)

target_sources(
    device
    PUBLIC
        FILE_SET device_module
        TYPE CXX_MODULES
        FILES device.cxxm mouse.cxxm keyboard.cxxm control/keycode.cxxm
)
target_link_libraries(device PRIVATE SDL3::SDL3-shared svl::base)
add_library(svl::device ALIAS device)
