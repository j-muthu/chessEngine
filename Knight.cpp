#include "Knight.h"
#include <cmath>

Knight::Knight(Colour c) : Piece(c) {}

Knight::~Knight() {}

bool Knight::validMoveDir(const Position& start, const Position& end, bool) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Knight moves in L-shape.
    return (fileDiff == 2 && rankDiff == 1) || (fileDiff == 1 && rankDiff == 2);
}
