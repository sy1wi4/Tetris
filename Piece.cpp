//
// Created by sylwia on 5/29/21.
//

#include <unistd.h>
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


void Piece::draw(GUI* gui, int x, int y) {

    std::cout << "RYSUJ TO" << std::endl;
    for (const auto & i : this->block){
        for (int j : i){
            if (j) std::cout << "1 ";
            else std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int start_x = (gui->getWindowWidth() - BOARD_WIDTH) / 2;
    int start_y = gui->getWindowHeight() - BOARD_HEIGHT;
    std::cout << "start_x " << start_x << std::endl;
    std::cout << "start_y " << start_y << std::endl;

    for (int i = 0; i < BLOCK_SIDE; i++){
        for (int j = 0; j < BLOCK_SIDE; j++){

            if (block[i][j]){
//                SDL_Rect rect{ x, y, SQUARE_SIDE, SQUARE_SIDE};
                std::cout << i << j << std::endl;
                std::cout << "x " << start_x + ((x + j) * SQUARE_SIDE) << std::endl;
                std::cout << "y " << start_y + ((y + i) * SQUARE_SIDE) << std::endl;

                gui->draw_square(start_x + ((x + j) * SQUARE_SIDE),
                                 start_y + ((y + i) * SQUARE_SIDE),
                                 SQUARE_SIDE);

            }
        }
    }
}

