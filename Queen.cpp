#include "Queen.h"
#include <cmath>

/**
 * @brief Constructor for Queen.
 * @param c The colour of the queen.
 */
Queen::Queen(Colour c) : Piece(c) {}

/**
 * @brief Destructor for Queen.
 */
Queen::~Queen() {}

/**
 * @brief Gets the name of the piece.
 * @return "Queen".
 */
std::string Queen::getName() const {
    return "Queen";
}

/**
 * @brief Checks if the queen can move from start to end position.
 * @param start The starting position.
 * @param end The ending position.
 * @param isCapture True if there's an enemy piece at the end position (not used for queen).
 * @return True if the movement pattern is valid for a queen.
 */
bool Queen::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    (void)isCapture;  // Unused for queen

    int absFileDiff = std::abs(end.file - start.file);
    int absRankDiff = std::abs(end.rank - start.rank);
    
    // Queen moves like rook (along rank or file) or bishop (diagonally)
    bool rookMove = (absFileDiff == 0 && absRankDiff != 0) || 
    (absFileDiff != 0 && absRankDiff == 0);
    bool bishopMove = absFileDiff == absRankDiff && absFileDiff > 0;
    
    return rookMove || bishopMove;
}
