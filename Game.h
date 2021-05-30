//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H


#include "GUI.h"
#include "GameBoard.h"
#include "Pieces.h"

class Game {
public:
    Game();
    void start();
private:
    GUI* gui;
    SDL_Event event;
    GameBoard* board;
    Pieces* pieces;
    Piece current_piece;
    Piece next_piece;
};


#endif //TETRIS_GAME_H
