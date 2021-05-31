//
// Created by sylwia on 5/30/21.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <vector>
#include "GUI.h"
#include "Piece.h"


#define EMPTY 0
#define TAKEN 1

class GameBoard {
public:
    GameBoard();
    GameBoard(int rows, int cols);

    // TODO: ???
//    friend std::ostream& operator<<(std::ostream& stream, const GameBoard& board);

    void print();

    void init();
    void place_piece(Piece piece, int x, int y);  // piece placed; x,y - upper left square
    bool can_move(Piece piece, int x, int y);
    void draw_stored_pieces(GUI* gui);
private:
    int rows;
    int cols;
    std::vector< std::vector<int>> board_matrix;
    static bool is_inside_board(int x, int y, int block_row, int block_co);
};


#endif //TETRIS_GAMEBOARD_H
