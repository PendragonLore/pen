#ifndef PEN_PEN_H
#define PEN_PEN_H

#include <SDL2/SDL_stdinc.h>

class Pen {
public:
    int init(Uint32 flags) const;

    void quit() const;
};

#endif //PEN_PEN_H
