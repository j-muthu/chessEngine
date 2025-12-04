#include "Rook.h"

/**
 * @brief Constructor for Rook.
 * @param c The colour of the rook.
 */
Rook::Rook(Colour c) : Piece(c) {}

/**
 * @brief Destructor for Rook.
 */
Rook::~Rook() {}

/**
 * @brief Gets the name of the piece.
 * @return "Rook".
 */
std::string Rook::getName() const {
    return "Rook";
}

/**
 * @brief Checks if the rook can move from start to end position.
 * @param start The starting position.
 * @param end The ending position.
 * @param isCapture True if there's an enemy piece at the end position (not used for rook).
 * @return True if the movement pattern is valid for a rook.
 */
bool Rook::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    (void)isCapture;  // Unused for rook
    
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    
    // Rook moves along rank (horizontal) or file (vertical)
    // One must be zero, the other non-zero
    return (fileDiff == 0 && rankDiff != 0) || (fileDiff != 0 && rankDiff == 0);
}

/**
 * @brief Rooks can be blocked.
 * @return True.
 */
bool Rook::canBeBlocked() const {
    return true;
}

/**
 * @brief Gets all possible move directions for a rook.
 * @return Vector of direction pairs (horizontal and vertical).
 */
std::vector<std::pair<int, int>> Rook::getMoveDirections() const {
    return {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
}

/**
 * @brief Rooks are sliding pieces.
 * @return True.
 */
bool Rook::isSliding() const {
    return true;
}
