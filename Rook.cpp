#include "Rook.h"

Rook::Rook(Colour c) : Piece(c) {}

Rook::~Rook() {}

bool Rook::validMoveDir(const Position& start, const Position& end, bool) const {
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    
    // Rook can move along ranks or files.
    return (fileDiff == 0 && rankDiff != 0) || (fileDiff != 0 && rankDiff == 0);
}

std::vector<Position> Rook::getMoveablePositions() const {
    // Rook can move any number of squares horizontally or vertically.
    return {Position{1,0}, Position{0,1}, Position{-1,0}, Position{0,-1}};
}