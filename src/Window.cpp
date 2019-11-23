#include "Window.hpp"
#include "FailedToInitialize.hpp"
#include "Types.hpp"

namespace pen {
Window::Window(const std::string &title, Rectangle geometry) {
    internal_window = SDL_CreateWindow(
            title.c_str(),
            geometry.x, geometry.y, geometry.w, geometry.h,
            SDL_WINDOW_SHOWN
    );

    if (internal_window == nullptr) {
        throw FailedToInitialize(SDL_GetError());
    }
}

Window::~Window() {
    if (internal_window != nullptr) {
        SDL_DestroyWindow(internal_window);
    }
}

SDL_Window *Window::internal() const noexcept { return internal_window; }

const std::string Window::title() const noexcept { return SDL_GetWindowTitle(internal_window); }

Point Window::generic_geometry_lookup(void func(SDL_Window *, int *, int *)) const noexcept {
    int x, y;

    func(internal_window, &x, &y);

    return Point{x, y};
}

Point Window::position() const noexcept {
    return generic_geometry_lookup(&SDL_GetWindowPosition);
}

Point Window::size() const noexcept {
    return generic_geometry_lookup(&SDL_GetWindowSize);
}
}