#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

/**
 * @brief Class representing knights. The move in an L-shape
 * and can jump over other pieces.
 */
class Knight : public Piece {
public:
    /** @copydoc Piece::Piece */
    Knight(Colour c);
    
    /** @copydoc Piece::~Piece */
    ~Knight() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "Knight";}

    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override {return false;}

    /** @copydoc Piece::isSliding() */
    bool isSliding() const override {return false;}

    /** @copydoc Piece::getMoveablePositions() */
    std::vector<Position> getMoveablePositions() const override;
};

#endif
