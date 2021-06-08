//
// Created by sylwia on 5/29/21.
//

#include "Piece.h"

/*
 Piece block format:
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
    block[sqr1 / block_side][sqr1 % block_side] = 1;
    block[sqr2 / block_side][sqr2 % block_side] = 1;
    block[sqr3 / block_side][sqr3 % block_side] = 1;
    block[sqr4 / block_side][sqr4 % block_side] = 1;
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
    int start_x = (gui->getWindowWidth() - board_width) / 2;
    int start_y = gui->getWindowHeight() - board_height - square_side;

    SDL_SetRenderDrawColor(gui->getRenderer(), 212, 174, 51, 0xFF);

    for (int i = 0; i < block_side; i++){
        for (int j = 0; j < block_side; j++){

            if (block[i][j]){
                gui->draw_square(start_x + ((x + j) * square_side),
                                 start_y + ((y + i) * square_side),
                                 square_side);
            }
        }
    }

}

void Piece::rotate() {
    int rotated[block_side][block_side] = {0};

    for(int i = 0; i < block_side; i++){
        for (int j = 0; j < block_side; j++){
            rotated[i][j] = block[block_side - j - 1][i];
        }
    }

    for(int i = 0; i < block_side; i++){
        for (int j = 0; j < block_side; j++){
            block[i][j] = rotated[i][j];
        }
    }
}

