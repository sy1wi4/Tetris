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
    for (int i = 0; i < BLOCK_SIDE; i++){
        for (int j = 0; j < BLOCK_SIDE; j++){
            if (piece(i,j)) {
                board_matrix[i + y][j + x] = TAKEN;
            }
        }
    }
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
            x + block_col < COLS &&
            y + block_row >= 0 &&
            y + block_row < ROWS
    );
}

bool GameBoard::can_move(Piece piece, int x, int y) {
    for (int i = 0; i < BLOCK_SIDE; i++){
        for(int j = 0; j < BLOCK_SIDE; j++){
            if (piece(i,j)){
                if (!is_inside_board(x, y, i, j)) {
                    std::cout << "OUTSIDE BOARD,  x: " << x + j << " y: " << y + i << std::endl;
                    return false;
                }
                if (board_matrix[y + i][x + j] == TAKEN){
                    std::cout << "TAKEN,  x: " << x + j << " y: " << y + i << std::endl;
                    return false;
                }
            }
        }
    }
    return true;
}

void GameBoard::draw_stored_pieces(GUI *gui) {
    // upper left corner of board
    int start_x = (gui->getWindowWidth() - BOARD_WIDTH) / 2;
    int start_y = gui->getWindowHeight() - BOARD_HEIGHT;

    SDL_SetRenderDrawColor(gui->getRenderer(), 96, 0, 128,0xFF);


    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (board_matrix[i][j]){
                gui->draw_square(start_x + (j * SQUARE_SIDE),
                                 start_y + (i * SQUARE_SIDE),
                                 SQUARE_SIDE);
            }
        }
    }
}



