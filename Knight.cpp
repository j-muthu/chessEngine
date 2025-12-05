#include "Knight.h"
#include <cmath>

/**
 * @brief Constructor for Knight.
 * @param c The colour of the knight.
 */
Knight::Knight(Colour c) : Piece(c) {}

/**
 * @brief Destructor for Knight.
 */
Knight::~Knight() {}

/**
 * @brief Gets the name of the piece.
 * @return "Knight".
 */
std::string Knight::getName() const {
    return "Knight";
}

/**
 * @brief Checks if the knight can move from start to end position.
 * @param start The starting position.
 * @param end The ending position.
 * @param isCapture True if there's an enemy piece at the end position (not used for knight).
 * @return True if the movement pattern is valid for a knight.
 */
bool Knight::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    (void)isCapture;  // Unused for knight
    
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Knight moves in L-shape: 2 squares one way, 1 square perpendicular
    return (fileDiff == 2 && rankDiff == 1) || (fileDiff == 1 && rankDiff == 2);
}
