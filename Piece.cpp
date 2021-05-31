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


Piece::Piece() {
    ;
}

// every piece consists of 4 squares
Piece::Piece(int sqr1, int sqr2, int sqr3, int sqr4) {
    // row = sqr/5, col = sqr%5
    block[sqr1 / BLOCK_SIDE][sqr1 % BLOCK_SIDE] = 1;
    block[sqr2 / BLOCK_SIDE][sqr2 % BLOCK_SIDE] = 1;
    block[sqr3 / BLOCK_SIDE][sqr3 % BLOCK_SIDE] = 1;
    block[sqr4 / BLOCK_SIDE][sqr4 % BLOCK_SIDE] = 1;
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

// TODO:
// (x, y) - upper left corner
void Piece::draw(GUI* gui, int x, int y) {
    SDL_SetRenderDrawColor(gui->getRenderer(), 212, 174, 51, 0xFF);

    for (auto & i : block){
        for (int j : i){

            if (j){
                SDL_Rect rect{ x, 0, SQUARE_SIDE, SQUARE_SIDE};
                SDL_RenderFillRect(gui->getRenderer(), &rect);
                SDL_RenderPresent(gui->getRenderer());
            }
        }
    }
}

