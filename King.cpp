#include "King.h"
#include <cmath>

King::King(Colour c) : Piece(c) {}

King::~King() {}

bool King::validMoveDir(const Position& start, const Position& end, bool) const {    
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Kings can normally move 1 square in any direction.
    if (fileDiff <= 1 && rankDiff <= 1 && (fileDiff > 0 || rankDiff > 0)) {
        return true;
    }
    
    // If the king is trying to castle, it moves 2 files.
    // Castling validity is checked in ChessGame.
    if (rankDiff == 0 && fileDiff == 2) {
        return true;
    }
    
    return false;
}

bool King::isCastlingMove(const Position& start, const Position& end) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    return fileDiff == 2 && rankDiff == 0;
}
