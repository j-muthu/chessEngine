#include "ChessGame.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

ChessGame::ChessGame() : activeColour(Colour::WHITE), boardLoaded(false), 
gameOver(false), whiteCanCastleKingside(false), whiteCanCastleQueenside(false),
blackCanCastleKingside(false), blackCanCastleQueenside(false) {
    // Initialise board's positions to null pointers.
    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            board[file][rank] = nullptr;
        }
    }
}

ChessGame::~ChessGame() {
    clearBoard();
}

void ChessGame::clearBoard() {
    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            // Deallocating any pieces still present.
            if (board[file][rank]) {
                delete board[file][rank];
                board[file][rank] = nullptr;
            }
        }
    }
}

Piece* ChessGame::pieceFromChar(char c) {
    Colour colour = isupper(c) ? Colour::WHITE : Colour::BLACK;

    char lower = tolower(c);
    switch (lower) {
        case 'p': 
            return new Pawn(colour);
        case 'r': 
            return new Rook(colour);
        case 'n': 
            return new Knight(colour);
        case 'b': 
            return new Bishop(colour);
        case 'q': 
            return new Queen(colour);
        case 'k': 
            return new King(colour);
        default: 
            return nullptr;
    }
}

bool ChessGame::strToPos(const string& posStr, Position& pos) const {
    if (posStr.length() != 2) {
        return false;
    }

    char fileChar = toupper(posStr[0]);
    char rankChar = posStr[1];
    if (fileChar < 'A' || fileChar > 'H' || rankChar < '1' || rankChar > '8') {
        return false;
    }
    pos.file = fileChar - 'A';
    pos.rank = rankChar - '1';
    return true;
}

Piece* ChessGame::getPieceAtPos(const Position& pos) const {
    if (!pos.isValid()) return nullptr;
    return board[pos.file][pos.rank];
}

bool ChessGame::isPathClear(const Position& start, const Position& end) const {
    int fileDiff = end.file - start.file;
    int rankDiff = end.rank - start.rank;
    
    // Single-square steps across files/ranks - can be -1, 0, or 1 
    // depending on the file/rank difference 
    // between the start and end positions.
    int fileStep = (fileDiff == 0) ? 0 : (fileDiff > 0 ? 1 : -1);
    int rankStep = (rankDiff == 0) ? 0 : (rankDiff > 0 ? 1 : -1);
    
    int currentFile = start.file + fileStep;
    int currentRank = start.rank + rankStep;
    
    while (currentFile != end.file || currentRank != end.rank) {
        if (board[currentFile][currentRank]) {
            return false;
        }
        currentFile += fileStep;
        currentRank += rankStep;
    }
    
    return true;
}

bool ChessGame::isSquareAttacked(const Position& pos, 
    Colour attackingColour) const {
    // Check whether any attacking colour piece can move 
    // to the specified position.
    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            Piece* piece = board[file][rank];
            if (!piece || piece->getColour() != attackingColour) continue;

            Position attackerPos(file, rank);
            if (piece->validMoveDir(attackerPos, pos, true)) {
                if (piece->canBeBlocked()) {
                    if (isPathClear(attackerPos, pos)) {
                        return true;
                    }
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}

bool ChessGame::isInCheck(Colour kingColour) const {
    Position kingPos = getKingPosition(kingColour);
    return isSquareAttacked(kingPos, oppositeColour(kingColour));
}

bool ChessGame::moveLeavesKingInCheck(const Position& start, const Position& end, 
    Colour movingColour) {
    Piece* movingPiece = board[start.file][start.rank];
    Piece* capturedPiece = board[end.file][end.rank];

    // Temporarily make the move.
    board[end.file][end.rank] = movingPiece;
    board[start.file][start.rank] = nullptr;
    // If the king moved, update its position.
    Position oldKingPos = getKingPosition(movingColour);
    bool kingMoved = (oldKingPos == start);
    if (kingMoved) {
        Position newKingPos = end;
        if (movingColour == Colour::WHITE) {
            whiteKingPos = newKingPos;
        } else {
            blackKingPos = newKingPos;
        }
    }

    bool inCheck = isInCheck(movingColour);
    
    // Restore the board to the original state.
    board[start.file][start.rank] = movingPiece;
    board[end.file][end.rank] = capturedPiece;
    // Moving the king back if it moved.
    if (kingMoved) {
        if (movingColour == Colour::WHITE) {
            whiteKingPos = oldKingPos;
        } else {
            blackKingPos = oldKingPos;
        }
    }
    
    return inCheck;
}

bool ChessGame::moveValidityChecks(const Position& start,
    const Position& end) {
    Piece* piece = getPieceAtPos(start);
    Piece* targetPiece = getPieceAtPos(end);
    bool isCapture = (targetPiece);

    // Can't capture an allied piece, nor a king.
    if ((targetPiece && 
        targetPiece->getColour() == piece->getColour()) ||
        end == whiteKingPos || end == blackKingPos) {
        return false;
    }

    // Piece must be allowed to move in the given direction,
    // it must not be blocked, and it must not leave its own king in check.
    return (piece->validMoveDir(start, end, isCapture) &&
        (!piece->canBeBlocked() || isPathClear(start, end)) && 
        !moveLeavesKingInCheck(start, end, piece->getColour()));
}

bool ChessGame::isValidCastling(const Position& start, 
    const Position& end, bool& kingside) const {
    Piece* piece = getPieceAtPos(start);
    if ((start != whiteKingPos && start != blackKingPos) ||
        piece->getHasMoved()) {
        return false;
    }

    Colour kingColour = piece->getColour();
    int direction = (end.file > start.file) ? 1 : -1;
    kingside = (direction == 1);
    // Check whether the king can castle on the implied side.
    // note the <colour>CanCastle<King/Queen>Side implies whether
    // the corresponding rook is at their destination position.
    if (kingColour == Colour::WHITE) {
        if ((kingside && !whiteCanCastleKingside) ||
        (!kingside && !whiteCanCastleQueenside)) {
            return false;
        }
    } else {
        if ((kingside && !blackCanCastleKingside) ||
        (!kingside && !blackCanCastleQueenside)) {
            return false;
        }
    }
    // King can't castle out of check.
    if (isInCheck(kingColour)) return false;
    
    // Given we've verified the corresponding rook's castling ability,
    // get the position of the rook (i.e. the corner of the board
    // on the castling side).
    int rookFile = kingside ? 7 : 0;
    int rank = start.rank;
    
    // There must be no pieces between the king and the rook.
    int checkStart = min(start.file, rookFile) + 1;
    int checkEnd = max(start.file, rookFile);
    for (int file = checkStart; file < checkEnd; file++) {
        if (board[file][rank]) {
            return false;
        }
    }
    
    // King can't castle through or into check.
    Position middlePos(start.file + direction, rank);
    if (isSquareAttacked(middlePos, oppositeColour(kingColour)) ||
    isSquareAttacked(end, oppositeColour(kingColour))) {
        return false;
    }

    return true;
}

bool ChessGame::isMoveLegal(const Position& start, const Position& end) {
    Piece* piece = getPieceAtPos(start);
    if (!piece) {
        return false;
    }
    
    // If the move is a castling attempt, check it is valid.
    if ((start == whiteKingPos || start == blackKingPos) &&
    abs(end.file - start.file) == 2) {
        bool kingside = false;
        return isValidCastling(start, end, kingside);
    }
    
    // Check all other conditions for the move's validity.
    return moveValidityChecks(start, end);
}

bool ChessGame::hasLegalMoves(Colour colourToCheck) {
    // Check all pieces of the specified colour
    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            
            Piece* piece = board[file][rank];
            if (!piece || piece->getColour() != colourToCheck) continue;

            // Try all possible destination squares
            for (int destFile = 0; destFile < 8; destFile++) {
                for (int destRank = 0; destRank < 8; destRank++) {

                    if (isMoveLegal(Position(file, rank), 
                    Position(destFile, destRank))) {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

void ChessGame::makeMove(const Position& start, const Position& end, 
    Piece*& capturedPiece) {
    Piece* movingPiece = board[start.file][start.rank];
    capturedPiece = board[end.file][end.rank];
    
    // Check whether this is a castling move.
    bool isCastling = false;
    bool kingMoving = (start == whiteKingPos || start == blackKingPos);
    if (kingMoving) {
        int fileDiff = abs(end.file - start.file);
        if (fileDiff == 2) {
            isCastling = true;
        }
    }
    
    // Move the piece.
    board[end.file][end.rank] = movingPiece;
    board[start.file][start.rank] = nullptr;
    movingPiece->setHasMoved();

    // Update the king's position if necessary, and corresponding castling
    // booleans.
    if (kingMoving) {
        if (movingPiece->getColour() == Colour::WHITE) {
            whiteKingPos = end;
            whiteCanCastleKingside = false;
            whiteCanCastleQueenside = false;
        } else {
            blackKingPos = end;
            blackCanCastleKingside = false;
            blackCanCastleQueenside = false;
        }
        
        // If the king is castling, the corresponding rook must be moved.
        if (isCastling) {
            int direction = (end.file > start.file) ? 1 : -1;
            int rookStartFile = (direction == 1) ? 7 : 0;
            int rookEndFile = start.file + direction;
            int rank = start.rank;
            
            Piece* rook = board[rookStartFile][rank];
            board[rookEndFile][rank] = rook;
            board[rookStartFile][rank] = nullptr;
            rook->setHasMoved();
        }
    }

    // If a rook has moved from its original position, update
    // the castling ability booleans.
    if (start == Position(0,0)) {
        whiteCanCastleQueenside = false;
    } else if (start == Position(7,0)) {
        whiteCanCastleKingside = false;
    } else if (start == Position(0,7)) {
        blackCanCastleQueenside = false;
    } else if (start == Position(7,7)) {
        blackCanCastleKingside = false;
    }
}

void ChessGame::checkCheckAndEndgame(Colour c) {
    bool inCheck = isInCheck(c);
    bool hasMovesAvailable = hasLegalMoves(c);
    if (inCheck && !hasMovesAvailable) {
        cout << c << " is in checkmate" << endl;
        gameOver = true;
    } else if (!inCheck && !hasMovesAvailable) {
        cout << "Stalemate!" << endl;
        gameOver = true;
    } else if (inCheck) {
        cout << c << " is in check" << endl;
    }
}

void ChessGame::loadState(const string& fen) {
    // Clear existing board and reset the state variables.
    clearBoard();
    boardLoaded = false;
    gameOver = false;
    whiteCanCastleKingside = false;
    whiteCanCastleQueenside = false;
    blackCanCastleKingside = false;
    blackCanCastleQueenside = false;
    
    // Split the FEN string into its 3 fields.
    istringstream iss(fen);
    string piecePlacement, activeColourStr, castlingStr;
    iss >> piecePlacement >> activeColourStr >> castlingStr;
    
    // Parse the first field - the pieces' positions on the board.
    int file = 0;
    int rank = 7;  // FEN string starts from highest rank (index 7).
    for (char c : piecePlacement) {
        if (c == '/') {
            file = 0;
            --rank;
        } else if (isdigit(c)) {
            file += (c - '0');
        } else {
            // Create the piece on the heap.
            Piece* piece = pieceFromChar(c);
            board[file][rank] = piece;     
            // If the piece is a king, store its position.
            if (tolower(c) == 'k') {
                if (piece->getColour() == Colour::WHITE) {
                    whiteKingPos = Position(file, rank);
                } else {
                    blackKingPos = Position(file, rank);
                }
            }
            ++file;
        }
    }
    
    // Parse active colour (i.e. the colour whose turn it is to move).
    activeColour = (activeColourStr == "b" || activeColourStr == "B") ? 
    Colour::BLACK : Colour::WHITE;
    
    // Parse castling abilities. 
    // Note all four booleans are initalised to false.
    if (castlingStr != "-") {
        for (char c : castlingStr) {
            switch (c) {
                case 'K': 
                    whiteCanCastleKingside = true; 
                    break;
                case 'Q': 
                    whiteCanCastleQueenside = true; 
                    break;
                case 'k': 
                    blackCanCastleKingside = true; 
                    break;
                case 'q': 
                    blackCanCastleQueenside = true; 
                    break;
            }
        }
    }
    
    boardLoaded = true;
    cout << "A new board state is loaded!" << endl;
    
    // Check whether the active colour is in check 
    // and/or has any moves available.
    checkCheckAndEndgame(activeColour);
}

void ChessGame::submitMove(const string& startStr, const string& endStr) {
    if (!boardLoaded) {
        cerr << "No board has been loaded!" << endl;
        return;
    }
    if (gameOver) {
        cerr  << "The game is already over!" << endl;
        return;
    }

    Position start, end;
    if (!strToPos(startStr, start)) {
        cerr  << "Invalid start position: " << startStr << endl;
        return;
    }
    if (!strToPos(endStr, end)) {
        cerr  << "Invalid end position: " << endStr << endl;
        return;
    }

    if (start == end) {
        cerr  << "Start and end positions are the same!" << endl;
        return;
    }

    Piece* piece = getPieceAtPos(start);
    if (!piece) {
        cerr << "There is no piece at position " 
        << start << "!" << endl;
        return;
    }
    
    if (piece->getColour() != activeColour) {
        cerr << "It is not " << piece->getColour() 
        << "'s turn to move!" << endl;
        return;
    }
    
    // Setting up boolean variables for whether the king is castling.
    bool kingMoving = (start == whiteKingPos || start == blackKingPos);
    bool isCastling = (kingMoving && abs(end.file - start.file) == 2);
    bool kingside = false;

    // Checking the validity of the move,
    // with separate checks for castling and non-castling moves.
    if ((!isCastling && !moveValidityChecks(start, end)) ||
    (isCastling && !isValidCastling(start, end, kingside))) {
        cerr << piece->getColour() << "'s " << piece->getName() 
                << " cannot move to " << end << "!" << endl;
        return;
    }
    
    // Output the move.
    cout << piece->getColour() << "'s " << piece->getName() 
            << " moves from " << start << " to " 
            << end;
    Piece* targetPiece = getPieceAtPos(end);
    if (targetPiece) {
        cout << " taking " << targetPiece->getColour() 
        << "'s " << targetPiece->getName();
    } else if (isCastling) {
        cout << " castling";
        if (kingside) {
            cout << " kingside";
        } else {
            cout << " queenside";
        }
    }
    cout << endl;

    // Delete the piece if one was captured.
    Piece* capturedPiece = nullptr;
    makeMove(start, end, capturedPiece);
    if (capturedPiece) delete capturedPiece;
    
    // Switch active colour.
    Colour enemyColour = oppositeColour(activeColour);
    activeColour = enemyColour;
    
    // See whether this move results in the enemy being in check, 
    // checkmate, or stalemate.
    checkCheckAndEndgame(enemyColour);
}