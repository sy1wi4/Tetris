//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GUI_H
#define TETRIS_GUI_H

#include <iostream>
#include <SDL2/SDL.h>

class GUI {
public:
    GUI();
    int init();
    void clear_window();

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};


#endif //TETRIS_GUI_H
