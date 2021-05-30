//
// Created by sylwia on 5/30/21.
//

#include "GUI.h"

GUI::GUI() {
    init();
}

int GUI::init() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // clean up on exit
    atexit(SDL_Quit);

    // create renderer
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window){
        fprintf(stderr, "Couldn't set 640x480x8 window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer){
        fprintf(stderr, "Couldn't create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}
