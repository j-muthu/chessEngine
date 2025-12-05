#ifndef PIECE_H
#define PIECE_H

#include "Position.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Enum for the two chess piece colours.
 */
enum class Colour {WHITE, BLACK};

/**
 * @brief Overloading of the << operator to allow the chess piece colour enum
 * to be displayed to console output as a string.
 * @param os A reference to the output stream.
 * @param c The colour to be displayed to the console.
 * @return A reference to the output stream with the colour 
 * appended as a string.
 */
std::ostream& operator<<(std::ostream& os, const Colour& c);

class ChessGame;

/**
 * @brief Abstract base class that all chess pieces inherit from.
 */
class Piece {
protected:
    Colour colour;
    bool hasMoved;
    
public:
    /**
     * @brief Piece constructor.
     * @param c The piece's colour.
     */
    Piece(Colour c);
    
    /**
     * @brief Piece destructor.
     */
    virtual ~Piece();
    
    /**
     * @brief Getter to return the piece's colour.
     * @return The piece's colour.
     */
    Colour getColour() const {return colour;}
    
    /**
     * @brief Gets the name of the piece as a string.
     * @return The name of the piece as a string.
     */
    virtual std::string getName() const = 0;
    
    /**
     * @brief Checks if the piece has moved from the position it originally
     * held when the board was loaded.
     * @return True if the piece has moved, false otherwise.
     */
    bool getHasMoved() const {return hasMoved;}
    
    /**
     * @brief Sets the hasMoved boolean to true to update the fact that a piece 
     * has moved from the position it held when the board was loaded.
     */
    void setHasMoved() {hasMoved = true;}
    
    /**
     * @brief Checks if the piece can legally move from the start to the end
     * position (i.e. whether it is a legal move direction). This method
     * doesn't check for obstructions or check conditions.
     * @param start Start position.
     * @param end End position.
     * @param isCapture True if there's an enemy piece at the end position,
     * false otherwise.
     * @return True if the movement direction is legal for the piece, false
     * otherwise.
     */
    virtual bool validMoveDir(const Position& start, const Position& end, 
        bool isCapture) const = 0;
    
    /**
     * @brief Checks if the piece can be blocked by other pieces along its
     * normal movement path. Knights can't be blocked as they jump over 
     * other pieces, nor can kings as they normally only move 1 square.
     * @return True if the piece's path can be blocked, false otherwise.
     */
    virtual bool canBeBlocked() const = 0;
};

#endif // PIECE_H
