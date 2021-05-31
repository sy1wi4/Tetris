//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GUI_H
#define TETRIS_GUI_H

#include <iostream>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class GUI {
public:
    GUI();
    int init();
    void clear_window();

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
    void draw_square(int x, int y, int side);
    void draw_stored_pieces();
    void draw_next_piece();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int window_width;
public:
    int getWindowWidth() const;

    int getWindowHeight() const;

private:
    int window_height;

};


#endif //TETRIS_GUI_H
