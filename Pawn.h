#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

/**
 * @brief Class representing a Pawn chess piece.
 * 
 * Pawns can move forward one square, or two squares on their first move.
 * They capture diagonally forward.
 */
class Pawn : public Piece {
public:
    /**
     * @brief Constructor for Pawn.
     * @param c The colour of the pawn.
     */
    Pawn(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~Pawn() override;
    
    /**
     * @brief Gets the name of the piece.
     * @return "Pawn".
     */
    std::string getName() const override;
    
    /**
     * @brief Checks if the pawn can move from start to end position.
     * @param start The starting position.
     * @param end The ending position.
     * @param isCapture True if there's an enemy piece at the end position.
     * @return True if the movement pattern is valid for a pawn.
     */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /**
     * @brief Pawns can be blocked.
     * @return True.
     */
    bool canBeBlocked() const override {return true;}
};

#endif // PAWN_H
