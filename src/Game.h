//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "GUI.h"
#include "GameBoard.h"
#include "Pieces.h"

#define STEP_TIME 700

#define BOARD_WIDTH (COLS * SQUARE_SIDE)
#define BOARD_HEIGHT (ROWS * SQUARE_SIDE)



class Game {
public:
    Game();
    void start();
    void reset_current_piece_coord();
    void handle_key(SDL_Event event);
    int get_current_x() const;
    int get_current_y() const;

private:
    GUI* gui;
    SDL_Event event;
    GameBoard* board;
    Pieces* pieces;
    Piece current_piece;

    int current_x;
    int current_y;
    Piece next_piece;

    bool can_rotate();
};


#endif //TETRIS_GAME_H
