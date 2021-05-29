//
// Created by sylwia on 5/29/21.
//

#include "Piece.h"

/*
 Piece block format:
  0 1 2 3 4
0 # # # # #
1 # # # # #
2 # # # # #
3 # # # # #
4 # # # # #


    0  1  2  3  4

0   0  1  2  3  4
1   5  6  7  8  9
2   10 11 12 13 14
3   15 16 17 18 19
4   20 21 22 23 24
 */


// every piece consists of 4 squares
Piece::Piece(int sqr1, int sqr2, int sqr3, int sqr4) {
    // row = sqr/5, col = sqr%5
    block[sqr1 / 5][sqr1 % 5] = 1;
    block[sqr2 / 5][sqr2 % 5] = 1;
    block[sqr3 / 5][sqr3 % 5] = 1;
    block[sqr4 / 5][sqr4 % 5] = 1;
}

std::ostream &operator<<(std::ostream &stream, const Piece &piece) {
    for (const auto & i : piece.block){
        for (int j : i){
            if (j) stream << "1 ";
            else stream << "* ";
        }
        stream << std::endl;
    }
    stream << std::endl;
}
