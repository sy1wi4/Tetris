//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "GUI.h"
#include "GameBoard.h"
#include "Pieces.h"

constexpr int step_time = 700;



class Game {
public:
    Game();
    void init();
    void start();
    void reset_current_piece_coord();
    void handle_key(SDL_Event event);
    int get_current_x() const;
    int get_current_y() const;
    void draw_next_piece();

private:
    GUI* gui;
    GameBoard* board;
    Pieces* pieces;
    Piece current_piece;
    Piece next_piece;
    SDL_Event event;
    int current_x;
    int current_y;

    bool can_rotate();
};


#endif //TETRIS_GAME_H
