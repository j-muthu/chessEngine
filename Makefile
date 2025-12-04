chess: ChessMain.o ChessGame.o Position.o Piece.o Pawn.o Rook.o Knight.o Bishop.o Queen.o King.o
	g++ -Wall -g ChessMain.o ChessGame.o Position.o Piece.o Pawn.o Rook.o Knight.o Bishop.o Queen.o King.o -o chess

ChessMain.o: ChessMain.cpp ChessGame.h
	g++ -Wall -g -c ChessMain.cpp

ChessGame.o: ChessGame.cpp ChessGame.h Piece.h Position.h Pawn.h Rook.h Knight.h Bishop.h Queen.h King.h
	g++ -Wall -g -c ChessGame.cpp

Position.o: Position.cpp Position.h
	g++ -Wall -g -c Position.cpp

Piece.o: Piece.cpp Piece.h Position.h
	g++ -Wall -g -c Piece.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h Position.h
	g++ -Wall -g -c Pawn.cpp

Rook.o: Rook.cpp Rook.h Piece.h Position.h
	g++ -Wall -g -c Rook.cpp

Knight.o: Knight.cpp Knight.h Piece.h Position.h
	g++ -Wall -g -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h Position.h
	g++ -Wall -g -c Bishop.cpp

Queen.o: Queen.cpp Queen.h Piece.h Position.h
	g++ -Wall -g -c Queen.cpp

King.o: King.cpp King.h Piece.h Position.h
	g++ -Wall -g -c King.cpp

clean:
	rm -f *.o chess

.PHONY: clean