#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

/**
 * @brief Class representing rooks. They can move along ranks and files.
 */
class Rook : public Piece {
public:
    /** @copydoc Piece::Piece */
    Rook(Colour c);
    
    /** @copydoc Piece::~Piece */
    ~Rook() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "Rook";}
    
    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override {return true;}
};

#endif
