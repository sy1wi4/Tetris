//
// Created by sylwia on 5/29/21.
//

#include <iostream>
#include "Pieces.h"
#include "Piece.h"

Pieces::Pieces() {
    // add 7 types of pieces

    // square
    Piece p1(12,13,17,18);
    add(p1);

    // L
    Piece p2(7,12,17,18);
    add(p2);

    // L-mirrored
    Piece p3(7,12,17,16);
    add(p3);

    // I
    Piece p4(7,12,17,22);
    add(p4);

    // N
    Piece p5(8,13,12,17);
    add(p5);

    // N-mirrored
    Piece p6(7,12,13,18);
    add(p6);

    // T
    Piece p7(7,12,17,13);
    add(p7);
}

void Pieces::add(Piece piece) {
    pieces.push_back(piece);
}

std::ostream &operator<<(std::ostream &stream, const Pieces &p) {
    for(const auto & piece : p.pieces) {
        stream << piece << std::endl;
    }
}
