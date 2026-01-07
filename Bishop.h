#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

/**
 * @brief Class representing bishops. They move diagonally.
 */
class Bishop : public Piece {
public:
    /** @copydoc Piece::Piece() */
    Bishop(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~Bishop() override;
    
    /** @copydoc Piece::getName() */
    std::string getName() const override {return "Bishop";}

    /** @copydoc Piece::validMoveDir() */
    bool validMoveDir(const Position& start, const Position& end,
        bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked() */
    bool canBeBlocked() const override {return true;}

    /** @copydoc Piece::isSliding() */
    bool isSliding() const override {return true;}

    /** @copydoc Piece::getMoveablePositions() */
    std::vector<Position> getMoveablePositions() const override;
};

#endif
