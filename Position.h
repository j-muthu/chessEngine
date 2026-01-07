#ifndef POSITION_H
#define POSITION_H

#include <iostream>

/**
 * @brief Struct representing a position (file, rank) on the chess board.
 * Contains 2 integers 0-7 representing the position's file 
 * (column, corresponding to A-H) and rank (row, corresponding to 1-8).
 */
struct Position {
    int file;
    int rank;
    
    /**
     * @brief Default constructor, initialises (file, rank) = (0,0)
     */
    Position() : file(0), rank(0) {}
    
    /**
     * @brief Parameterised constructor.
     * @param f File (0-7).
     * @param r Rank (0-7).
     */
    Position(int f, int r) : file(f), rank(r) {}
    
    /**
     * @brief Equality operator to compare two positions.
     * @param other The other position to compare with.
     * @return True if both positions are equal (same file and rank),
     * false otherwise.
     */
    bool operator==(const Position& other) const;
    
    /**
     * @brief Inequality operator for positions.
     * @param other The other position to compare with.
     * @return True if positions have different files or ranks,
     * false otherwise.
     */
    bool operator!=(const Position& other) const;

    /**
     * @brief Addition operator for positions.
     * @param other The other position to be added.
     * @return A new position where the file is the sum of the two
     * operand positions' files, and likewise with the rank.
     */
    Position operator+(const Position& other) const;

    /**
     * @brief Compound assignment operator for positions.
     * @param other The other position to be added to the current position.
     * @return The current position where the file has been incremented by the
     * other positions file, and likewise with the rank.
     */
    Position& operator+=(const Position& other);
    
    /**
     * @brief Checks if the position is valid (on the 8x8 board) 
     * @return True if position is valid (both file and rank are 0-7),
     * false otherwise.
     */
    bool isValid() const;
    
};

/**
 * @brief Overloading of the << operator to allow the position struct to be 
 * displayed to the console output as an algebraic notation string.
 * E.g. Position(4,3) -> "E4".
 * @param os A reference to the output stream.
 * @param p The position to be displayed to the console.
 * @return The output stream with the algebraic notation string 
 * corresponding to the position appended to it.
 */
std::ostream& operator<<(std::ostream& os, const Position& p);

#endif
