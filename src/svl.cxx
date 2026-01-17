module;
#include <cstdlib>

module svl;
import svl.window;

int svl::run()
{
    using namespace svl;
    window core_window("SDL-Vulkan Learn", 480, 360, 0);
    return EXIT_SUCCESS;
}
