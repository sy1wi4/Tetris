//
// Created by sylwia on 5/29/21.
//

#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

#include <vector>
#include "Piece.h"


class Pieces {
public:
    Pieces();
    void add(Piece piece);
    friend std::ostream& operator<<(std::ostream& stream, const Pieces& pieces);

private:
    std::vector<Piece> pieces;
};


#endif //TETRIS_PIECES_H
