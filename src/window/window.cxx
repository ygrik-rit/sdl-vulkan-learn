module;
#include "svl_config.hxx"
#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>
module svl.window;

namespace svl
{
window::window(std::string   title,
               std::int32_t  width,
               std::int32_t  height,
               window::flags state)
    : title(std::move(title))
    , width(width)
    , height(height)
    , state(state)
{
    title = std::format("{} [{}]", title, svl::version::version);

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
    {
        spdlog::error("Cant init SDL: {}", SDL_GetError());
    }
}
window::window(const window& wnd) {}
window::~window() {}
} // namespace svl