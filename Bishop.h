#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

/**
 * @brief Class representing a Bishop chess piece.
 * 
 * Bishops can move any number of squares diagonally,
 * but cannot leap over other pieces.
 */
class Bishop : public Piece {
public:
    /** @copydoc Piece::Piece */
    Bishop(Colour c);
    
    /** @copydoc Piece::~Piece */
    ~Bishop() override;
    
    /** @copydoc Piece::getName */
    std::string getName() const override {return "Bishop";}

    /** @copydoc Piece::validMoveDir */
    bool validMoveDir(const Position& start, const Position& end,
        bool isCapture) const override;
    
    /** @copydoc Piece::canBeBlocked */
    bool canBeBlocked() const override;
    
    /**
     * @brief Gets all possible move directions for a bishop.
     * @return Vector of direction pairs (all diagonals).
     */
    std::vector<std::pair<int, int>> getMoveDirections() const override;
    
    /**
     * @brief Bishops are sliding pieces.
     * @return True.
     */
    bool isSliding() const override;
};

#endif // BISHOP_H
