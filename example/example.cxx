#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl;

int main()
{
    spdlog::info("SDL-Vulkan Learn version: {}", svl::version::version);
    return svl::run();
}