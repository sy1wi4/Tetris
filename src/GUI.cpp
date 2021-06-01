//
// Created by sylwia on 5/30/21.
//

#include <unistd.h>
#include "GUI.h"


GUI::GUI() {
    window_width = WINDOW_WIDTH;
    window_height = WINDOW_HEIGHT;
    init();
}

int GUI::init() {
    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // clean up on exit
    atexit(SDL_Quit);

    // create window
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window){
        fprintf(stderr, "Couldn't set 640x480x8 window: %s\n", SDL_GetError());
        exit(1);
    }

    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer){
        fprintf(stderr, "Couldn't create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

void GUI::clear_window() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}

SDL_Renderer *GUI::getRenderer() const {
    return renderer;
}

int GUI::getWindowWidth() const {
    return window_width;
}

int GUI::getWindowHeight() const {
    return window_height;
}

void GUI::draw_square(int x, int y, int side) {
    SDL_Rect rect{x, y, side - GAP, side - GAP};
    SDL_RenderFillRect(renderer, &rect);

}

void GUI::draw_title() {

}
