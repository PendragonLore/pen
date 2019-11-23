#include "Pen.hpp"

int main(int argc, const char *argv[]) {
    pen::Rectangle geometry;
    geometry.x = SDL_WINDOWPOS_UNDEFINED;
    geometry.y = SDL_WINDOWPOS_UNDEFINED;
    geometry.w = 800;
    geometry.h = 800;

    pen::Window window("Hi", geometry);
}
