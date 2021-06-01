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


const int &Piece::operator()(int x, int y) const {
    return block[x][y];
}

int &Piece::operator()(int x, int y) {
    return block[x][y];
}


void Piece::draw(GUI* gui, int x, int y) {

    // upper left corner of board
    int start_x = (gui->getWindowWidth() - BOARD_WIDTH) / 2;
    int start_y = gui->getWindowHeight() - BOARD_HEIGHT - SQUARE_SIDE;

    SDL_SetRenderDrawColor(gui->getRenderer(), 212, 174, 51, 0xFF);

    for (int i = 0; i < BLOCK_SIDE; i++){
        for (int j = 0; j < BLOCK_SIDE; j++){

            if (block[i][j]){
                gui->draw_square(start_x + ((x + j) * SQUARE_SIDE),
                                 start_y + ((y + i) * SQUARE_SIDE),
                                 SQUARE_SIDE);
            }
        }
    }

}

void Piece::rotate() {
    int rotated[BLOCK_SIDE][BLOCK_SIDE] = {0};

    for(int i = 0; i < BLOCK_SIDE; i++){
        for (int j = 0; j < BLOCK_SIDE; j++){
            rotated[i][j] = block[BLOCK_SIDE - j - 1][i];
        }
    }

    for(int i = 0; i < BLOCK_SIDE; i++){
        for (int j = 0; j < BLOCK_SIDE; j++){
            block[i][j] = rotated[i][j];
        }
    }
}

