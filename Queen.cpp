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
    
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    int absFileDiff = std::abs(fileDiff);
    int absRankDiff = std::abs(rankDiff);
    
    // Queen moves like rook (along rank or file) or bishop (diagonally)
    bool rookMove = (fileDiff == 0 && rankDiff != 0) || (fileDiff != 0 && rankDiff == 0);
    bool bishopMove = absFileDiff == absRankDiff && absFileDiff > 0;
    
    return rookMove || bishopMove;
}

/**
 * @brief Queens can be blocked.
 * @return True.
 */
bool Queen::canBeBlocked() const {
    return true;
}

/**
 * @brief Gets all possible move directions for a queen.
 * @return Vector of direction pairs (all 8 directions).
 */
std::vector<std::pair<int, int>> Queen::getMoveDirections() const {
    return {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},  // Rook directions
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}  // Bishop directions
    };
}

/**
 * @brief Queens are sliding pieces.
 * @return True.
 */
bool Queen::isSliding() const {
    return true;
}
