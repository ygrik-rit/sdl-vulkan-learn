#include <cstdint>
#include <string>

#include <SDL3/SDL.h>

namespace svl::platform::window
{
class context
{
public:
    using flags = std::uint64_t;
    enum class flag : flags
    {
        FULLSCREEN          = SDL_WINDOW_FULLSCREEN,
        OCCLUDED            = SDL_WINDOW_OCCLUDED,
        HIDDEN              = SDL_WINDOW_HIDDEN,
        BORDERLESS          = SDL_WINDOW_BORDERLESS,
        RESIZABLE           = SDL_WINDOW_RESIZABLE,
        MINIMIZED           = SDL_WINDOW_MINIMIZED,
        MAXIMIZED           = SDL_WINDOW_MAXIMIZED,
        MOUSE_GRABBED       = SDL_WINDOW_MOUSE_GRABBED,
        INPUT_FOCUS         = SDL_WINDOW_INPUT_FOCUS,
        MOUSE_FOCUS         = SDL_WINDOW_MOUSE_FOCUS,
        EXTERNAL            = SDL_WINDOW_EXTERNAL,
        MODAL               = SDL_WINDOW_MODAL,
        HIGH_PIXEL_DENSITY  = SDL_WINDOW_HIGH_PIXEL_DENSITY,
        MOUSE_CAPTURE       = SDL_WINDOW_MOUSE_CAPTURE,
        MOUSE_RELATIVE_MODE = SDL_WINDOW_MOUSE_RELATIVE_MODE,
        ALWAYS_ON_TOP       = SDL_WINDOW_ALWAYS_ON_TOP,
        UTILITY             = SDL_WINDOW_UTILITY,
        TOOLTIP             = SDL_WINDOW_TOOLTIP,
        POPUP_MENU          = SDL_WINDOW_POPUP_MENU,
        KEYBOARD_GRABBED    = SDL_WINDOW_KEYBOARD_GRABBED,
        FILL_DOCUMENT       = SDL_WINDOW_FILL_DOCUMENT,
        TRANSPARENT         = SDL_WINDOW_TRANSPARENT,
        NOT_FOCUSABLE       = SDL_WINDOW_NOT_FOCUSABLE,
    };

    explicit context(std::string    title,
                     std::int32_t   width,
                     std::int32_t   height,
                     context::flags state);
    // TODO: Add posibility to create 2 or more windows with diff render
    // context, but common app logic and controls
    context(const context& wnd) {}
    ~context();

    void create();
    void destroy();
    void poll_event();

    [[nodiscard]] inline bool is_running() const { return running; }
    [[nodiscard]] inline bool is_fullscreen() const
    {
        return state & static_cast<flags>(flag::FULLSCREEN);
    }

    [[nodiscard]] inline void* get_native_sdl_window() const { return wnd; }

private:
    std::string    title {};
    std::int32_t   width {};
    std::int32_t   height {};
    context::flags state {};

    SDL_Window* wnd {};

    bool running {};
};
} // namespace svl::platform::window