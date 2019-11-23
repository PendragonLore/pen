#pragma once

#include <string>
#include "Types.hpp"

namespace pen {
class Window {
public:
    Window(const std::string &name, Rectangle geometry);

    ~Window();

    Point position() const noexcept;

    Point size() const noexcept;

    const std::string title() const noexcept;

    SDL_Window *internal() const noexcept;

private:
    Point generic_geometry_lookup(void func(SDL_Window *, int *, int *)) const noexcept;

    SDL_Window *internal_window;

};
} // namespace pen