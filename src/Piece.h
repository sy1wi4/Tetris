//
// Created by sylwia on 5/29/21.
//

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <ostream>
#include <vector>
#include "GUI.h"

constexpr int block_side = 5;
constexpr int square_side = 27;
constexpr int rows_number = 20;
constexpr int cols_number = 10;
constexpr int board_width = cols_number * square_side;
constexpr int board_height = rows_number * square_side;


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
    int block[block_side][block_side] = {0};
};


#endif //TETRIS_PIECE_H
