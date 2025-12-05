#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

/**
 * @brief Class representing pawns. They advance one square, or
 * optionally two squares on their first move. They capture diagonally forward.
 */
class Pawn : public Piece {
public:
    /** @copydoc Piece::Piece */
    Pawn(Colour c);
    
    /** @copydoc Piece::~Piece */
    ~Pawn() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "Pawn";}
    
    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override {return true;}
};

#endif
