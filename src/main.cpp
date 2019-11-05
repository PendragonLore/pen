#include "Pen.h"
#include "FailedToInitialize.h"

#include <SDL2/SDL.h>

int main() {
    SDL_Log("Pen is booting...");

    pen::Pen game("Test", std::pair<int, int>(800, 600));

    try {
        game.init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    } catch (pen::FailedToInizialize &exc) {
        SDL_Log("Failed to initialize SDL: %s", exc.what());
        return exc.code();
    }

    game.quit();

    return 0;
}
