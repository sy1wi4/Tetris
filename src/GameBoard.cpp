//
// Created by sylwia on 5/30/21.
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    this->rows = rows_number;
    this->cols = rows_number;
    init();
}

GameBoard::GameBoard(int rows, int cols) : rows(rows), cols(cols) {}

void GameBoard::init() {
    board_matrix.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board_matrix[i][j] = empty;
        }
    }
}

void GameBoard::place_piece(Piece piece, int x, int y) {
    for (int i = 0; i < block_side; i++){
        for (int j = 0; j < block_side; j++){
            if (piece(i,j)) {
                board_matrix[i + y][j + x] = taken;
            }
        }
    }
}

// check if given square of piece (coord: block_row, block_col) is inside game board
bool GameBoard::is_inside_board(int x, int y, int block_row, int block_col) {
    return (x + block_col >= 0 &&
            x + block_col < cols_number &&
            y + block_row >= 0 &&
            y + block_row < rows_number
    );
}

bool GameBoard::can_move(Piece piece, int x, int y) {
    for (int i = 0; i < block_side; i++){
        for(int j = 0; j < block_side; j++){
            if (piece(i,j)){
                if (!is_inside_board(x, y, i, j))
                    return false;
                if (board_matrix[y + i][x + j] == taken)
                    return false;
            }
        }
    }
    return true;
}

void GameBoard::draw_stored_pieces(GUI *gui) {
    // upper left corner of board
    int start_x = (gui->getWindowWidth() - board_width) / 2;
    int start_y = gui->getWindowHeight() - board_height - square_side;

    SDL_SetRenderDrawColor(gui->getRenderer(), 148, 148, 184,0xFF);


    for (int i = 0; i < rows_number; i++){
        for (int j = 0; j < cols_number; j++){
            if (board_matrix[i][j]){
                gui->draw_square(start_x + (j * square_side),
                                 start_y + (i * square_side),
                                 square_side);
            }
        }
    }
}

void GameBoard::draw_borders(GUI* gui) {
    int left_x = (gui->getWindowWidth() - board_width) / 2;
    int right_x = (gui->getWindowWidth() - board_width) / 2 + board_width;
    int start_y = gui->getWindowHeight() - board_height - square_side;

    SDL_SetRenderDrawColor(gui->getRenderer(), 104, 100, 118, 0xFF);

    for (int i = 0; i < rows_number; i++) {
        // left
        gui->draw_square(left_x - square_side,
                         start_y + (i * square_side),
                         square_side);

        // right
        gui->draw_square(right_x,
                         start_y + (i * square_side),
                         square_side);
    }

    for (int i = 0; i < cols_number + 2; i++) {
        // top
        gui->draw_square(left_x + (i - 1) * square_side,
                         start_y - square_side,
                         square_side);

        // bottom
        gui->draw_square(left_x + (i - 1) * square_side,
                         start_y + rows_number * square_side,
                         square_side);
    }
}

bool GameBoard::is_line_full(int y) {
    for (int i = 0; i < cols_number; i++){
        if (board_matrix[y][i] == empty){
            return false;
        }
    }
    return true;
}

// y is top square of last added piece - check only five down squares
void GameBoard::clear_full_lines(GUI* gui, int y) {

    for (int row = y; ((row < rows_number) && (row < y + 5)); row++){
        if (is_line_full(row)) {
            clear_line(row);
        }
    }
}

// move down the squares above given row
void GameBoard::clear_line(int y) {
    for (int row = y; row >= 0; row--){
        for (int col = 0; col < cols_number; col++){
            if (row == 0) board_matrix[row][col] = empty;
            else
                board_matrix[row][col] = board_matrix[row - 1][col];
        }
    }
}

bool GameBoard::check_game_over() {
    for (int i = 0; i < cols_number; i++) {
        if (board_matrix[1][i] == taken){
            return true;
        }
    }
    return false;
}


