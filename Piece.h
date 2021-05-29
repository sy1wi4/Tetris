//
// Created by sylwia on 5/29/21.
//

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <ostream>

#define BLOCK_SIDE 5

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
    Piece(int sqr1, int sqr2, int sqr3, int sqr4);
    friend std::ostream& operator<<(std::ostream& stream, const Piece& piece);
//private:
    int block[BLOCK_SIDE][BLOCK_SIDE] = {0};
};


#endif //TETRIS_PIECE_H
