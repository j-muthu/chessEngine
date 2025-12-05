#include "Pawn.h"
#include <cmath>

Pawn::Pawn(Colour c) : Piece(c) {}

Pawn::~Pawn() {}

bool Pawn::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    
    int direction = (colour == Colour::WHITE) ? 1 : -1;
    
    // Capture moves are diagonally ahead.
    if (isCapture) {
        return (std::abs(fileDiff) == 1) && (rankDiff == direction);
    }
    
    // Otherwise, can advance 1 square, or, if it hasn't moved,
    // 2 squares.
    if (fileDiff == 0 && 
        (rankDiff == direction ||
        (!hasMoved && rankDiff == 2 * direction))) {
        return true;
    }
    
    return false;
}
