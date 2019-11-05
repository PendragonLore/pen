#include "Pen.h"
#include "FailedToInitialize.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace pen {
Pen::Pen(const char *name, std::pair<int, int> window_size) : name_(name), window_size_(std::move(window_size)) {}

void Pen::init(Uint32 flags) {
    int error;

    if ((error = SDL_Init(flags))) {
        throw pen::FailedToInizialize(error, SDL_GetError());
    }

    constexpr int IMAGE_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG;

    if ((IMG_Init(IMAGE_FLAGS) & IMAGE_FLAGS) != IMAGE_FLAGS) {
        throw pen::FailedToInizialize(1, IMG_GetError());
    }

    // TODO: let the initial pos be custom
    if ((main_window_ = SDL_CreateWindow(name_, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                         window_size_.first, window_size_.second,
                                         SDL_WINDOW_OPENGL)) == nullptr) {
        throw pen::FailedToInizialize(1, SDL_GetError());
    }

    main_surface_ = SDL_GetWindowSurface(main_window_);
}

SDL_Surface *Pen::load_image(const char *path) {
    SDL_Surface *resource;

    if ((resource = IMG_Load(path)) == nullptr) {
        // TODO: throw a proper exception
        throw std::exception();
    }

    return resource;
}

void Pen::quit() {
    SDL_FreeSurface(main_surface_);
    main_surface_ = nullptr;

    SDL_DestroyWindow(main_window_);
    main_window_ = nullptr;

    IMG_Quit();
    SDL_Quit();
}

void Pen::sleep(Uint32 time) {
    SDL_Delay(time);
}
} // namespace pen
