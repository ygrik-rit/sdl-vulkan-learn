#include <catch2/catch_test_macros.hpp>
#include <libassert/assert-catch2.hpp>
#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl.renderer.texture;

import std;

TEST_CASE("Load KTX texture", "[renderer][texture][ktx]")
{
    using namespace svl;

    renderer::utils::texture example("res/textures/example.ktx");
}
