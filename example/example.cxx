#include <argparse/argparse.hpp>
#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl;
import std;

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("svl");

    program.add_argument("-r", "--res").help("Path to resource folder");

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        spdlog::error("Error parsing args: {}\n Args: {}",
                      err.what(),
                      program.help().str());
        return EXIT_FAILURE;
    }

    if (program.is_used("--res"))
    {
        spdlog::info("Parsed arguments:\n Resource folder = {}",
                     program.get<std::string>("--res"));
    }

    spdlog::info("SDL-Vulkan Learn version: {}", svl::version::version);
    return svl::run();
}