#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

/**
 * @brief Class representing queens.
 * They can move horizontally, vertically, or diagonally.
 */
class Queen : public Piece {
public:
    /** @copydoc Piece::Piece */
    Queen(Colour c);
    
    /** @copydoc Piece::~Piece */
    ~Queen() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "Queen";}

    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override {return true;}

    /** @copydoc Piece::isSliding() */
    bool isSliding() const override {return true;}

    /** @copydoc Piece::getMoveablePositions() */
    std::vector<Position> getMoveablePositions() const override;
};

#endif
