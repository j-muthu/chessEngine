#include "King.h"
#include <cmath>

/**
 * @brief Constructor for King.
 * @param c The colour of the king.
 */
King::King(Colour c) : Piece(c) {}

/**
 * @brief Destructor for King.
 */
King::~King() {}

/**
 * @brief Gets the name of the piece.
 * @return "King".
 */
std::string King::getName() const {
    return "King";
}

/**
 * @brief Checks if the king can move from start to end position.
 * 
 * This includes both normal king moves (one square) and castling (two squares horizontally).
 * 
 * @param start The starting position.
 * @param end The ending position.
 * @param isCapture True if there's an enemy piece at the end position.
 * @return True if the movement pattern is valid for a king.
 */
bool King::validMoveDir(const Position& start, const Position& end, bool isCapture) const {
    (void)isCapture;  // Unused directly, but castling can't be a capture
    
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    // Normal king move: one square in any direction
    if (fileDiff <= 1 && rankDiff <= 1 && (fileDiff > 0 || rankDiff > 0)) {
        return true;
    }
    
    // Castling move: two squares horizontally on same rank
    if (rankDiff == 0 && fileDiff == 2) {
        return true;  // Actual castling validity is checked in ChessGame
    }
    
    return false;
}

bool King::isCastlingMove(const Position& start, const Position& end) const {
    int fileDiff = std::abs(end.file - start.file);
    int rankDiff = std::abs(end.rank - start.rank);
    
    return fileDiff == 2 && rankDiff == 0;
}
