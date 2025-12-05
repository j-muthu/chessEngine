#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Colour c) : Piece(c) {}

Bishop::~Bishop() {}

// Note that bool, rather than bool isCapture is in the parameter list
// because it suppresses compiler warnings about unused parameters.
bool Bishop::validMoveDir(const Position& start, const Position& end, bool) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Bishop moves diagonally.
    return fileDiff == rankDiff && fileDiff > 0;
}