#include "Pen.h"
#include "FailedToInitialize.h"

#include <SDL2/SDL.h>

int main() {
    SDL_Log("Pen is booting...");

    Pen game;

    try {
        game.init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    } catch (FailedToInizialize &exc) {
        SDL_Log("Failed to initialize SDL: %s", exc.what());
        return exc.code();
    }

    game.quit();
    return 0;
}