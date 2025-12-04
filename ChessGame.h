#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Position.h"
#include "Piece.h"
#include <string>

/**
 * @brief Chess game class. 
 * 
 * Contains the board state (and can load in boards from FEN), 
 * checks moves' validity, and identifies check and end states.
 */
class ChessGame {
private:
    Piece* board[8][8]; // Board positions are indexed by (file, rank).
    Position whiteKingPos; 
    Position blackKingPos;
    Colour activeColour;
    bool boardLoaded; // Whether a board has actually been loaded in.
    bool gameOver; // Whether the current game is over.
    
    // Castling abilities
    bool whiteCanCastleKingside;
    bool whiteCanCastleQueenside;
    bool blackCanCastleKingside;
    bool blackCanCastleQueenside;
    
    /**
     * @brief Clears the chessboard, deallocating the pieces.
     */
    void clearBoard();
    
    /**
     * @brief Creates a piece on the heap from a FEN char.
     * @param c The FEN char representing the piece - uppercase means White,
     * lowercase means Black.
     * @return Pointer to the piece on the heap.
     */
    Piece* pieceFromChar(char c);
    
    /**
     * @brief Converts a given position string (e.g. "E4") 
     * into a specified Position struct.
     * @param posStr The position string to convert.
     * @param pos The Position struct to be written to.
     * @return True if parsing succeeded, false otherwise.
     */
    bool strToPos(const std::string& posStr, Position& pos) const;
    
    /**
     * @brief Getter to return a pointer to the piece at a specified position.
     * @param pos The position to check.
     * @return Pointer to the piece at the specified position.
     * Returns null pointer if there is no piece or the specified position is
     * invalid.
     */
    Piece* getPieceAtPos(const Position& pos) const;
    
    /**
     * @brief Checks if a given position is under attack by a specified colour 
     * (i.e. if any piece of the specified colour could move to the given
     * position).
     * @param pos The position to be checked.
     * @param attackingColour The attacking colour.
     * @return True if the position is under attack, false otherwise.
     */
    bool isSquareAttacked(const Position& pos, Colour attackingColour) const;
    
    /**
     * @brief Checks if the king of the specified colour is in check.
     * @param kingColour The colour of the king to check.
     * @return True if the king is in check, false otherwise.
     */
    bool isInCheck(Colour kingColour) const;
    
    /**
     * @brief Checks whether the path between two positions is clear. 
     * The positions are assumed to lie along a straight line (a file, rank,
     * or diagonal), so that the path is a straight line 
     * through squares on the board.
     * @param start The start position.
     * @param end The end position.
     * @return True if there are no pieces between the specified start and 
     * end positions, false otherwise.
     */
    bool isPathClear(const Position& start, const Position& end) const;
    
    /**
     * @brief Checks if a specified move by would leave the moving player's 
     * king in check.
     * @param start The starting position.
     * @param end The ending position.
     * @param movingColour The colour of the piece being moved.
     * @return True if the move would leave the moving player's king in check,
     * false otherwise.
     */
    bool moveLeavesKingInCheck(const Position& start, const Position& end, 
        Colour movingColour);
    
    /**
     * @brief Helper function for whether a given chess move is valid 
     * according to 4 criteria:
     * - a piece cannot capture an allied piece, nor a king.
     * - a piece must be able to move in the given direction,
     * - a piece must not be blocked by other pieces from making a move. 
     * - a piece cannot leave the allied king in check.
     * @param start The starting position.
     * @param end The ending position.
     * @return True if the move is valid according to the 4 criteria, false
     * otherwise.
     */
    bool moveValidityChecks(const Position& start, const Position& end);

    /**
     * @brief Checks if a given move by the king is a valid attempt to castle.
     * @param start The king's starting position.
     * @param end The king's ending position.
     * @param kingside Whether the castling attempt is kingside or queenside.
     * This boolean is updated within the method.
     * @return True if the move is a valid castle, false otherwise.
     */
    bool isValidCastling(const Position& start, const Position& end, 
        bool& kingside) const;
    
    /**
     * @brief Checks if the specified colour has any legal moves available.
     * @param colourToCheck The colour to check.
     * @return True if at least one legal move exists, false otherwise.
     */
    bool hasLegalMoves(Colour colourToCheck);
    
    /**
     * @brief Checks if a specific move is legal. Note this function does not
     * actually make the move, nor does it check the colour 
     * of the moving piece.
     * @param start Start position.
     * @param end End position.
     * @return True if the move is legal, false otherwise.
     */
    bool isMoveLegal(const Position& start, const Position& end);
    
    /**
     * @brief Executes a specified move on the board. Note this function 
     * assumes that the move has been validated as legal.
     * @param start Start position.
     * @param end End position.
     * @param capturedPiece If a piece was captured, this parameter stores a
     * reference to a pointer to the captured piece.
     */
    void makeMove(const Position& start, const Position& end, 
        Piece*& capturedPiece);

    /**
     * @brief Checks whether the specified colour is in check or checkmate,
     * and whether the game is in stalemate.
     * @param c The specified colour to check.
     */
    void checkCheckAndEndgame(Colour c);
    
    /**
     * @brief Getter for the position of the king of the specified colour.
     * @param kingColour The colour of the king whose position is desired.
     * @return The specified king's position
     */
    Position getKingPosition(Colour kingColour) const {
        return (kingColour == Colour::WHITE) ? whiteKingPos : blackKingPos;
    }
    
    /**
     * @brief Returns the opposite colour to the provided colour.
     * @param c The colour whose opposite will be returned.
     * @return WHITE if c is BLACK, and vice versa.
     */
    Colour oppositeColour(Colour c) const {
        return (c == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
    }

public:
    /**
     * @brief Default constructor, initialising an empty chess game.
     */
    ChessGame();
    
    /**
     * @brief Destructor. Deallocates all pieces on the board.
     */
    ~ChessGame();
    
    /**
     * @brief Loads in a board state from a FEN string.
     * Also checks whether either side is in check from the outset,
     * or if the board is already in checkmate or stalemate.
     * Note it is assumed that the FEN string is valid (as mentioned
     * in the spec).
     * 
     * @param fen A valid FEN string.
     */
    void loadState(const std::string& fen);
    
    /**
     * @brief Attempts to make a move on the board. Checks whether the move is
     * valid, and if so, makes the move.
     * Displays relevant messages for invalid moves, captures, check, 
     * stalemate, and checkmate.
     * @param startStr Start position (as an algebraic chess notation 
     * string).
     * @param endStr End position (as an algebraic chess notation 
     * string).
     */
    void submitMove(const std::string& startStr, const std::string& endStr);
};

#endif // CHESSGAME_H
