#include "Queen.h"
#include <cmath>

Queen::Queen(Colour c) : Piece(c) {}

Queen::~Queen() {}

bool Queen::validMoveDir(const Position& start, const Position& end,
    bool) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Queen can move along a rank, file, or diagonally.
    return (fileDiff == 0 && rankDiff != 0) || 
    (fileDiff != 0 && rankDiff == 0) || 
    (fileDiff == rankDiff && fileDiff > 0);
}

std::vector<Position> Queen::getMoveablePositions() const {
    std::vector<Position> moves;
    // Can move in all directions.
    for (int file : {-1, 0, 1}) {
        for (int rank : {-1, 0, 1}) {
            if (file != 0 || rank != 0) {
                moves.push_back(Position{file, rank});
            }
        }
    }
    return moves;
}
