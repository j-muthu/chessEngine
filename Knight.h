#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

/**
 * @brief Class representing a Knight chess piece.
 * 
 * Knights move in an L-shape: two squares in one direction and one square
 * perpendicular to that. Knights can leap over other pieces.
 */
class Knight : public Piece {
public:
    /**
     * @brief Constructor for Knight.
     * @param c The colour of the knight.
     */
    Knight(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~Knight() override;
    
    /**
     * @brief Gets the name of the piece.
     * @return "Knight".
     */
    std::string getName() const override;

    /**
     * @brief Checks if the knight can move from start to end position.
     * @param start The starting position.
     * @param end The ending position.
     * @param isCapture True if there's an enemy piece at the end position (not used for knight).
     * @return True if the movement pattern is valid for a knight.
     */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /**
     * @brief Knights cannot be blocked (they leap over pieces).
     * @return False.
     */
    bool canBeBlocked() const override;
    
    /**
     * @brief Gets all possible move directions for a knight.
     * @return Vector of direction pairs (all L-shaped moves).
     */
    std::vector<std::pair<int, int>> getMoveDirections() const override;
    
    /**
     * @brief Knights are not sliding pieces.
     * @return False.
     */
    bool isSliding() const override;
};

#endif // KNIGHT_H
