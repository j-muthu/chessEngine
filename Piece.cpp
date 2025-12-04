#include "Piece.h"
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, const Colour& c) {
    if (c == Colour::WHITE) {
        os << "White";
    } else os << "Black";
    return os;
}

Piece::Piece(Colour c) : colour(c), hasMoved(false) {}

Piece::~Piece() {}

/**
 * @brief Gets the colour name as a string.
 * @return "White" or "Black".
 */
string Piece::getColourName() const {
    return (colour == Colour::WHITE) ? "White" : "Black";
}
