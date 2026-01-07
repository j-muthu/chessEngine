#include "King.h"
#include <cmath>

King::King(Colour c) : Piece(c) {}

King::~King() {}

bool King::validMoveDir(const Position& start, const Position& end,
    bool isCapture) const {    
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Kings can normally move 1 square in any direction.
    if (fileDiff <= 1 && rankDiff <= 1 && (fileDiff > 0 || rankDiff > 0)) {
        return true;
    }
    
    // If the king is trying to castle, it moves 2 files.
    // Note it cannot capture when it's trying to castle.
    // Full castling validity is checked in ChessGame.
    if (!isCapture && rankDiff == 0 && fileDiff == 2) {
        return true;
    }
    
    return false;
}

std::vector<Position> King::getMoveablePositions() const {
    std::vector<Position> moves;
    // Can move in all directions (but only 1 square).
    for (int file : {-1, 0, 1}) {
        for (int rank : {-1, 0, 1}) {
            if (file != 0 || rank != 0) {
                moves.push_back(Position{file, rank});
            }
        }
    }
    // Note that we don't need to check whether the king can castle,
    // because a necessary condition for the king to castle on a given
    // side is that it can also move just one square in that given direction.
    return moves;
}

bool King::isCastlingMove(const Position& start, const Position& end) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    return fileDiff == 2 && rankDiff == 0;
}
