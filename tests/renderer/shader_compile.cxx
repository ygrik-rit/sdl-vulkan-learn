#include <catch2/catch_test_macros.hpp>
#include <libassert/assert-catch2.hpp>
#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl.renderer.shader;
import std;

TEST_CASE("Compile shader", "[renderer][shader]")
{
    using namespace svl::renderer;

    shader::program shader;

    std::vector<char> bytecode_vert =
        shader.glsl_to_spirv("res/shaders/shader.glsl.vert",
                             shader::program::language::Vertex,
                             "main");
    ASSERT(!!bytecode_vert.empty(),
           "Error, compilation of null shader result",
           bytecode_vert);
    std::vector<char> bytecode_frag =
        shader.glsl_to_spirv("res/shaders/shader.glsl.frag",
                             shader::program::language::Fragment,
                             "main");
    ASSERT(!!bytecode_frag.empty(),
           "Error, compilation of null shader result",
           bytecode_frag);

    spdlog::info(
        "bytecode_vert: {}",
        std::string_view { bytecode_vert.data(), bytecode_vert.size() });
    spdlog::info(
        "bytecode_frag: {}",
        std::string_view { bytecode_frag.data(), bytecode_frag.size() });
}
