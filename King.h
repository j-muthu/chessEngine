#ifndef KING_H
#define KING_H

#include "Piece.h"

/**
 * @brief Class representing a King chess piece.
 * 
 * Kings can move one square in any direction.
 * They can also castle if certain conditions are met.
 */
class King : public Piece {
public:
    /**
     * @brief Constructor for King.
     * @param c The colour of the king.
     */
    King(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~King() override;
    
    /**
     * @brief Gets the name of the piece.
     * @return "King".
     */
    std::string getName() const override;

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
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /**
     * @brief Kings cannot be blocked for normal moves.
     * @return False.
     */
    bool canBeBlocked() const override;
    
    /**
     * @brief Gets all possible move directions for a king.
     * @return Vector of direction pairs (all 8 adjacent squares).
     */
    std::vector<std::pair<int, int>> getMoveDirections() const override;
    
    /**
     * @brief Kings are not sliding pieces.
     * @return False.
     */
    bool isSliding() const override;
    
    /**
     * @brief Checks if the move is a castling attempt.
     * @param start The starting position.
     * @param end The ending position.
     * @return True if the king is trying to castle (moving 2 squares horizontally).
     */
    bool isCastlingMove(const Position& start, const Position& end) const;
};

#endif // KING_H
