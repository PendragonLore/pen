#ifndef PEN_PEN_H
#define PEN_PEN_H

#include <utility>

#include <SDL2/SDL_video.h>

namespace pen {
class Pen {
public:
    explicit Pen(const char *name, std::pair<int, int> window_size);

    void init(Uint32 flags);

    void quit();

    void sleep(Uint32 time);

    SDL_Surface *load_image(const char *path);

private:
    const char *name_;

    std::pair<int, int> window_size_;

    SDL_Window *main_window_ = nullptr;
    SDL_Surface *main_surface_ = nullptr;
};
} // namespace pen

#endif //PEN_PEN_H
