#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl;
import std;

int main()
{
    try
    {
        svl::platform::window::context ctx("Coverage Test", 300, 400, {});
    }
    catch (svl::platform::window::window_error err)
    {
        spdlog::error("Global exception window_error: {}", err.what());
    }

    return EXIT_SUCCESS;
}