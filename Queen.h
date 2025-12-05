#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

/**
 * @brief Class representing a Queen chess piece.
 * 
 * Queens combine the power of rooks and bishops, moving any number of squares
 * along rank, file, or diagonal. They cannot leap over other pieces.
 */
class Queen : public Piece {
public:
    /**
     * @brief Constructor for Queen.
     * @param c The colour of the queen.
     */
    Queen(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~Queen() override;
    
    /**
     * @brief Gets the name of the piece.
     * @return "Queen".
     */
    std::string getName() const override;

    /**
     * @brief Checks if the queen can move from start to end position.
     * @param start The starting position.
     * @param end The ending position.
     * @param isCapture True if there's an enemy piece at the end position (not used for queen).
     * @return True if the movement pattern is valid for a queen.
     */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /**
     * @brief Queens can be blocked.
     * @return True.
     */
    bool canBeBlocked() const override {return true;}
};

#endif // QUEEN_H
