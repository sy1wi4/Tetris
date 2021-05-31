//
// Created by sylwia on 5/30/21.
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    this->rows = ROWS;
    this->cols = COLS;
    init();
}

GameBoard::GameBoard(int rows, int cols) : rows(rows), cols(cols) {}


void GameBoard::init() {
    board_matrix.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board_matrix[i][j] = EMPTY;
        }
    }
}

void GameBoard::place_piece(Piece piece, int x, int y) {

}

void GameBoard::print() {
    for (auto & i : board_matrix){
        for (int j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// check if given square of piece (coord: block_row, block_col) is inside game board
bool GameBoard::is_inside_board(int x, int y, int block_row, int block_col) {
    return (x + block_col >= 0 &&
            x + block_col < SQUARE_SIDE &&
            y + block_row >= 0 &&
            y + block_row < SQUARE_SIDE
    );
}

bool GameBoard::can_move(Piece piece, int x, int y) {
    for (int i = 0; i < BLOCK_SIDE; i++){
        for(int j = 0; j < BLOCK_SIDE; j++){
//            std::cout << i << " " << j << std::endl;
            if (piece(i,j)){
                if (!is_inside_board(x, y, i, j) || (board_matrix[x + j][y + i] == TAKEN)) {
                    return false;
                }
            }
        }
    }
    return true;
}



