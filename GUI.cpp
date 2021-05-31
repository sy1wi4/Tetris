//
// Created by sylwia on 5/30/21.
//

#include "GUI.h"

GUI::GUI() {
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
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

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

SDL_Window *GUI::getWindow() const {
    return window;
}

SDL_Renderer *GUI::getRenderer() const {
    return renderer;
}
