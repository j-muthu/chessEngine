#ifndef KING_H
#define KING_H

#include "Piece.h"

/**
 * @brief Class for kings. They can move one square in any direction, 
 * and can castle with rooks.
 */
class King : public Piece {
public:
    /** @copydoc Piece::Piece */
    King(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~King() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "King";}

    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override {return false;}
    
    /**
     * @brief Checks if the given move is a castling attempt.
     * @param start The starting position.
     * @param end The ending position.
     * @return True if the king is trying to castle, false otherwise.
     */
    bool isCastlingMove(const Position& start, const Position& end) const;
};

#endif
