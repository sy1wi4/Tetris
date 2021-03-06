//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <vector>
#include "GUI.h"
#include "Piece.h"

constexpr int empty = 0;
constexpr int taken = 1;


class GameBoard {
public:
    GameBoard();
    GameBoard(int rows, int cols);

    void init();
    void place_piece(Piece piece, int x, int y);  // piece placed; x,y - upper left square
    bool can_move(Piece piece, int x, int y);
    void draw_stored_pieces(GUI* gui);
    static void draw_borders(GUI* gui);
    void clear_full_lines(GUI* gui, int y);
    bool check_game_over();

private:
    int rows;
    int cols;
    std::vector< std::vector<int>> board_matrix;

    static bool is_inside_board(int x, int y, int block_row, int block_co);
    bool is_line_full(int y);
    void clear_line(int y);

};


#endif //TETRIS_GAMEBOARD_H
