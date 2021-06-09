//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GUI_H
#define TETRIS_GUI_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

constexpr int win_width = 800;
constexpr int win_height = 700;
constexpr int gap = 2; // pixels between squares


class GUI {
public:
    GUI();
    int init();
    void clear_window();
    int getWindowWidth() const;
    int getWindowHeight() const;
    SDL_Renderer* getRenderer() const;
    void draw_square(int x, int y, int side);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int window_width;
    int window_height;
};


#endif //TETRIS_GUI_H
