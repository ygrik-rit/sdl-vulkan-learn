add_subdirectory(utils)

add_library(renderer OBJECT)

target_sources(
    renderer
    PUBLIC
        FILE_SET renderer_module
            TYPE CXX_MODULES
            FILES
                shader/program.cxxm
                queue/command_manager.cxxm
                renderer.cxxm
                buffer/manager.cxxm
                texture/texture.cxxm
)
target_link_libraries(
    renderer
    PRIVATE
        KTX::ktx
        Vulkan::HppModule
        glslang::SPIRV
        glslang::glslang
        glslang::glslang-default-resource-limits
        svl::base
        svl::platform
        svl::utils
)

add_library(svl::renderer ALIAS renderer)
