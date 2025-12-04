#include "Pawn.h"
#include <cmath>

/**
 * @brief Constructor for Pawn.
 * @param c The colour of the pawn.
 */
Pawn::Pawn(Colour c) : Piece(c) {}

/**
 * @brief Destructor for Pawn.
 */
Pawn::~Pawn() {}

/**
 * @brief Gets the name of the piece.
 * @return "Pawn".
 */
std::string Pawn::getName() const {
    return "Pawn";
}

/**
 * @brief Checks if the pawn can move from start to end position.
 * @param start The starting position.
 * @param end The ending position.
 * @param isCapture True if there's an enemy piece at the end position.
 * @return True if the movement pattern is valid for a pawn.
 */
bool Pawn::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    
    // Direction depends on colour: white moves up (positive rank), black moves down
    int direction = (colour == Colour::WHITE) ? 1 : -1;
    
    // Capture move: diagonal, one square forward
    if (isCapture) {
        return (std::abs(fileDiff) == 1) && (rankDiff == direction);
    }
    
    // Non-capture move: straight forward
    if (fileDiff != 0) {
        return false;  // Can't move diagonally without capture
    }
    
    // One square forward
    if (rankDiff == direction) {
        return true;
    }
    
    // Two squares forward on first move
    if (!hasMoved && rankDiff == 2 * direction) {
        return true;
    }
    
    return false;
}

/**
 * @brief Pawns can be blocked.
 * @return True.
 */
bool Pawn::canBeBlocked() const {
    return true;
}

/**
 * @brief Gets all possible move directions for a pawn.
 * 
 * Returns diagonal capture directions based on colour.
 * Used for checking if a pawn attacks a square.
 * 
 * @return Vector of direction pairs for pawn attacks.
 */
std::vector<std::pair<int, int>> Pawn::getMoveDirections() const {
    int direction = (colour == Colour::WHITE) ? 1 : -1;
    // Pawns attack diagonally
    return {{-1, direction}, {1, direction}};
}

/**
 * @brief Pawns are not sliding pieces.
 * @return False.
 */
bool Pawn::isSliding() const {
    return false;
}
