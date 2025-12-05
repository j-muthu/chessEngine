#include "Queen.h"
#include <cmath>

Queen::Queen(Colour c) : Piece(c) {}

Queen::~Queen() {}

bool Queen::validMoveDir(const Position& start, const Position& end, bool) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Queen can move along a rank, file, or diagonally.
    return (fileDiff == 0 && rankDiff != 0) || 
    (fileDiff != 0 && rankDiff == 0) || 
    (fileDiff == rankDiff && fileDiff > 0);
}
