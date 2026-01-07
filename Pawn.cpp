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

std::vector<Position> Pawn::getMoveablePositions() const {
    std::vector<Position> moves;

    // Pawns can move ahead one square, or diagonally 1 square
    // if capturing.
    int rankInFront = colour == Colour::WHITE ? 1 : -1;
    for (int file : {-1, 0, 1}) {
        moves.push_back(Position{file, rankInFront});
    }

    // If the pawn hasn't moved, it can also move ahead two squares.
    if (hasMoved) {
        moves.push_back(Position{0, rankInFront});
    }
    
    return moves;
}
