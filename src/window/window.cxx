module;

#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>

#include "svl_config.hxx"
module svl.window;

import svl.device;

namespace svl::window
{
context::context(std::string    title,
                 std::int32_t   width,
                 std::int32_t   height,
                 context::flags state)
    : title(std::move(title))
    , width(width)
    , height(height)
    , state(state)
{
    title = std::format("{} [{}]", title, svl::version::version);

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_NAME_STRING,
                               title.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_VERSION_STRING,
                               svl::version::version.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_IDENTIFIER_STRING,
                               svl::constants::appdata::identifier.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_CREATOR_STRING,
                               svl::constants::appdata::creator.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_COPYRIGHT_STRING,
                               svl::constants::appdata::copyright.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_URL_STRING,
                               svl::constants::appdata::url.c_str());
    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_TYPE_STRING,
                               svl::constants::appdata::type.c_str());

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
    {
        spdlog::error("Cant init SDL: {}", SDL_GetError());
        throw std::runtime_error("Window construct error");
    }
}
context::context(const context& wnd) {}
context::~context()
{
    if (running)
    {
        SDL_DestroyWindow(wnd);
        running = false;
    }
    SDL_Quit();
}

void context::create()
{
    if (running)
    {
        return;
    }

    wnd = SDL_CreateWindow(title.c_str(), width, height, state);
    if (!wnd)
    {
        spdlog::error("Cant create SDL Window: {}", SDL_GetError());
        throw std::runtime_error("Window create error");
    }
    running = true;
}
void context::destroy()
{
    if (running)
    {
        SDL_DestroyWindow(wnd);
        running = false;
    }
}
void context::poll_event()
{
    static SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT) [[unlikely]]
        {
            destroy();
            break;
        }
        device::mouse::process_event(event);
        device::keyboard::process_event(event);
    }
}

} // namespace svl::window