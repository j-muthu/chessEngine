#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

/**
 * @brief Class representing a Rook chess piece.
 * 
 * Rooks can move any number of squares along rank or file,
 * but cannot leap over other pieces.
 */
class Rook : public Piece {
public:
    /**
     * @brief Constructor for Rook.
     * @param c The colour of the rook.
     */
    Rook(Colour c);
    
    /** @copydoc Piece::~Piece() */
    ~Rook() override;
    
    /**
     * @brief Gets the name of the piece.
     * @return "Rook".
     */
    std::string getName() const override;
    
    /**
     * @brief Checks if the rook can move from start to end position.
     * @param start The starting position.
     * @param end The ending position.
     * @param isCapture True if there's an enemy piece at the end position (not used for rook).
     * @return True if the movement pattern is valid for a rook.
     */
    bool validMoveDir(const Position& start, const Position& end, bool isCapture) const override;
    
    /**
     * @brief Rooks can be blocked.
     * @return True.
     */
    bool canBeBlocked() const override {return true;}
};

#endif // ROOK_H
