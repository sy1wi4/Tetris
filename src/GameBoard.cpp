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

void GameBoard::handle_key(SDL_Event event) {

}

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

