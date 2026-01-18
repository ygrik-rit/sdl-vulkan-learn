#include <SDL3/SDL_mouse.h>

namespace svl::device::mouse
{
enum class button
{
    left   = SDL_BUTTON_LEFT,
    middle = SDL_BUTTON_MIDDLE,
    right  = SDL_BUTTON_RIGHT,
    x1     = SDL_BUTTON_X1,
    x2     = SDL_BUTTON_X2,
};
} // namespace svl::device::mouse