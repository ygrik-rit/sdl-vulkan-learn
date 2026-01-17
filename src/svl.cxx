module;
#include <cstdlib>

module svl;
import svl.window;

int svl::run()
{
    using namespace svl;
    window core_window("SDL-Vulkan Learn", 480, 360, 0);

    core_window.create();

    while (core_window.is_running())
    {
        core_window.poll_event();
    }
    return EXIT_SUCCESS;
}
