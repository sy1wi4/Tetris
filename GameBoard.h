//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <vector>
#include "GUI.h"
#include "Piece.h"

#define EMPTY 0
#define TAKEN 1

class GameBoard {
public:
    GameBoard();
    GameBoard(int rows, int cols);

    // TODO: ???
//    friend std::ostream& operator<<(std::ostream& stream, const GameBoard& board);

    void print();

    void init();
    void handle_key(SDL_Event event);
    void place_piece(Piece piece, int x, int y);  // piece placed; x,y - ll square
private:
    int rows;
    int cols;
    std::vector< std::vector<int>> board_matrix;
};


#endif //TETRIS_GAMEBOARD_H
