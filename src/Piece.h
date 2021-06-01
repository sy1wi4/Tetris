//
// Created by sylwia on 5/29/21.
//

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <ostream>
#include <vector>
#include "GUI.h"

#define BLOCK_SIDE 5
#define SQUARE_SIDE 27
#define BOARD_WIDTH (COLS * SQUARE_SIDE)
#define BOARD_HEIGHT (ROWS * SQUARE_SIDE)
#define BORDER_WIDTH 10
#define ROWS 20
#define COLS 10

/*
 Piece block format:
  0 1 2 3 4
0 # # # # #
1 # # # # #
2 # # # # #
3 # # # # #
4 # # # # #

 0  1  2  3  4
 5  6  7  8  9
 10 11 12 13 14
 15 16 17 18 19
 20 21 22 23 24
 */

class Piece {
public:
    Piece();
    Piece(int sqr1, int sqr2, int sqr3, int sqr4);

    friend std::ostream& operator<<(std::ostream& stream, const Piece& piece);
    const int& operator()(int x, int y) const;
    int& operator()(int x, int y);

    void rotate();
    void draw(GUI* gui, int x, int y);

private:
    int block[BLOCK_SIDE][BLOCK_SIDE] = {0};
};


#endif //TETRIS_PIECE_H
