//
// Created by sylwia on 5/29/21.
//

#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

#include <vector>
#include "Piece.h"

constexpr int pieces_number = 7;

class Pieces {
public:
    Pieces();
    void add(Piece piece);
    friend std::ostream& operator<<(std::ostream& stream, const Pieces& pieces);
    Piece& get_random_piece();
private:
    std::vector<Piece> pieces;
};


#endif //TETRIS_PIECES_H
