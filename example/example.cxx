#include <argparse/argparse.hpp>
#include <spdlog/spdlog.h>

#include "svl_config.hxx"

import svl;
import std;

int main(int argc, char* argv[])
{
    try
    {
        argparse::ArgumentParser program("svl");
        program.add_argument("-r", "--res").help("Path to resource folder");
        program.parse_args(argc, argv);
        if (program.is_used("--res"))
        {
            spdlog::info("Parsed arguments:\n Resource folder = {}",
                         program.get<std::string>("--res"));
        }
    }
    catch (const std::bad_array_new_length& err)
    {
        spdlog::error("Error create parser: {}", err.what());
        return EXIT_FAILURE;
    }
    catch (const std::exception& err)
    {
        spdlog::error("Error parsing args: {}\n Args: {}",
                      err.what(),
                      program.help().str());
        return EXIT_FAILURE;
    }

    spdlog::info("SDL-Vulkan Learn version: {}", svl::version::version);
    return svl::run();
}