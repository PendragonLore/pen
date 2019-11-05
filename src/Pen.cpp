#include "Pen.h"
#include "FailedToInitialize.h"

#include <SDL2/SDL.h>

int Pen::init(Uint32 flags) const {
    int error;

    if ((error = SDL_Init(flags))) {
        throw FailedToInizialize(error, SDL_GetError());
    }

    return 0;
}

void Pen::quit() const {
    SDL_Quit();
}