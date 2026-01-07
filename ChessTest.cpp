#include"ChessGame.h"

#include<iostream>

using std::cout;
using std::endl;

int main() {	
	ChessGame cg;

	cout << "\n================== TEST ==================" << endl;

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");


	cg.submitMove("E2", "E4");
	cg.submitMove("F7", "F5");
	cg.submitMove("E4", "F5");
	cg.submitMove("G8", "F6");
	cg.submitMove("F1", "C4");
	cg.submitMove("E7", "E5");
	cg.submitMove("D1", "H5");
	cout << endl;

	cout << " === invalid move === \n";
	cg.submitMove("F8", "E7");
	cg.submitMove("G7", "G6");
	cg.submitMove("G1", "F3");
	cg.submitMove("F8", "C5");
	cg.submitMove("F3", "E5");
	cout << endl;

	cout << " === invalid castle attempt === \n";
	cg.submitMove("E8", "G8");
	cout << endl;

	cout << " === pinned === \n";
	cg.submitMove("G6", "G5");
	cg.submitMove("C5", "E7");
	cg.submitMove("E5", "G6");
	cout << endl;

	cout << " === blocked vertical === \n";
	cg.submitMove("D8", "D4");
	cout << endl;

	cout << " === blocked diagonal === \n";
	cg.submitMove("E7", "H4");
	cg.submitMove("E7", "F8");
	cout << endl;

	cout << " === discovered check === " << endl;
	cg.submitMove("G6", "H8");
	cg.submitMove("E8", "E7");
	cout << endl;

	cout << " === white castle === " << endl;
	cg.submitMove("E1", "G1");
	cout << endl;

	cout << " === stalemate === " << endl;
	cg.loadState("5k2/8/6K1/3Q4/8/8/8/8 w -");
	cg.submitMove("D5", "E6");
	cout << endl;

	cout << " === testing castling === " << endl;
	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	cg.submitMove("e2", "e4");
	cg.submitMove("e7", "e5");
	cg.submitMove("f1", "d3");
	cg.submitMove("d7", "d6");
	cg.submitMove("g1","f3");
	cg.submitMove("g8","h6");
	cg.submitMove("E1", "G1");
    cout << endl;

	cout << " === initialising a board with pawn out of place to check it can't"
    << " advance 2 spaces === " << endl;
    cg.loadState("rnbqkbnr/ppppppp1/p7/8/8/8/PPPPPPPP/RNBQKBNR b KQkq");
    cg.submitMove("a6", "a4");
    cg.submitMove("g7", "g5");
	cout << endl;

	cout << " === Black king has only 1 valid move. === " << endl;
	cg.loadState("8/3R4/3Q4/3k4/4P3/8/8/8 b -");
	cg.submitMove("d5", "d6");
	cg.submitMove("d5", "e4");
	cout << endl;

	cout << endl;
	cout << "=========================\n";
    cout << "Reti vs. Tartakower (1910)\n";
    cout << "=========================\n\n";

    // Standard Start Position
    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. e4 c6
    cg.submitMove("E2", "E4");
    cg.submitMove("C7", "C6");
    cout << '\n';

    // 2. d4 d5
    cg.submitMove("D2", "D4");
    cg.submitMove("D7", "D5");
    cout << '\n';

    // 3. Nc3 dxe4
    cg.submitMove("B1", "C3");
    cg.submitMove("D5", "E4");
    cout << '\n';

    // 4. Nxe4 Nf6
    cg.submitMove("C3", "E4");
    cg.submitMove("G8", "F6");
    cout << '\n';

    // 5. Qd3 e5
    cg.submitMove("D1", "D3");
    cg.submitMove("E7", "E5");
    cout << '\n';

    // 6. dxe5 Qa5+
    cg.submitMove("D4", "E5");
    cg.submitMove("D8", "A5");
    cout << '\n';

    // 7. Bd2 Qxe5
    cg.submitMove("C1", "D2");
    cg.submitMove("A5", "E5");
    cout << '\n';

    // 8. O-O-O Nxe4
    // Note: Ensure your engine handles castling (Queenside here)
    cg.submitMove("E1", "C1"); 
    cg.submitMove("F6", "E4");
    cout << '\n';

    // 9. Qd8+ Kxd8
    cg.submitMove("D3", "D8");
    cg.submitMove("e8", "D8");
    cout << '\n';

    // 10. Bg5+ Kc7
    // Double check from Bishop and Rook
    cg.submitMove("D2", "G5");
    cg.submitMove("D8", "C7");
    cout << '\n';

    // 11. Bd8#
    cg.submitMove("G5", "D8");
    cout << '\n';

	cout << endl;

	cout << "=========================\n";
    cout << "Morphy vs. Duke/Count (1858)\n";
    cout << "=========================\n\n";

    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. e4 e5
    cg.submitMove("E2", "E4");
    cg.submitMove("E7", "E5");
    cout << '\n';

    // 2. Nf3 d6
    cg.submitMove("G1", "F3");
    cg.submitMove("D7", "D6");
    cout << '\n';

    // 3. d4 Bg4
    cg.submitMove("D2", "D4");
    cg.submitMove("C8", "G4");
    cout << '\n';

    // 4. dxe5 Bxf3
    cg.submitMove("D4", "E5");
    cg.submitMove("G4", "F3");
    cout << '\n';

    // 5. Qxf3 dxe5
    cg.submitMove("D1", "F3");
    cg.submitMove("D6", "E5");
    cout << '\n';

    // 6. Bc4 Nf6
    cg.submitMove("F1", "C4");
    cg.submitMove("G8", "F6");
    cout << '\n';

    // 7. Qb3 Qe7
    cg.submitMove("F3", "B3");
    cg.submitMove("D8", "E7");
    cout << '\n';

    // 8. Nc3 c6
    cg.submitMove("B1", "C3");
    cg.submitMove("C7", "C6");
    cout << '\n';

    // 9. Bg5 b5
    cg.submitMove("C1", "G5");
    cg.submitMove("B7", "B5");
    cout << '\n';

    // 10. Nxb5 cxb5
    cg.submitMove("C3", "B5");
    cg.submitMove("C6", "B5");
    cout << '\n';

    // 11. Bxb5+ Nbd7
    cg.submitMove("C4", "B5");
    cg.submitMove("B8", "D7");
    cout << '\n';

    // 12. O-O-O Rd8
    cg.submitMove("E1", "C1"); // Queenside Castle
    cg.submitMove("A8", "D8");
    cout << '\n';

    // 13. Rxd7 Rxd7
    cg.submitMove("D1", "D7");
    cg.submitMove("D8", "D7");
    cout << '\n';

    // 14. Rd1 Qe6
    cg.submitMove("H1", "D1");
    cg.submitMove("E7", "E6");
    cout << '\n';

    // 15. Bxd7+ Nxd7
    cg.submitMove("B5", "D7");
    cg.submitMove("F6", "D7");
    cout << '\n';

    // 16. Qb8+ Nxb8
    cg.submitMove("B3", "B8");
    cg.submitMove("D7", "B8");
    cout << '\n';

    // 17. Rd8#
    cg.submitMove("D1", "D8");
    cout << '\n';


	cout << endl;
	cout << "=========================\n";
    cout << "Gibaud vs. Lazard (1924)\n";
    cout << "=========================\n\n";

    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. d4 Nf6
    cg.submitMove("D2", "D4");
    cg.submitMove("G8", "F6");
    cout << '\n';

    // 2. Nd2 e5
    cg.submitMove("B1", "D2");
    cg.submitMove("E7", "E5");
    cout << '\n';

    // 3. dxe5 Ng4
    cg.submitMove("D4", "E5");
    cg.submitMove("F6", "G4");
    cout << '\n';

    // 4. h3 Ne3
    // White cannot take the knight (f2 is pinned or pawn move rules apply)
    // If White takes (f2xe3), Queen checks mate on h4 next.
    cg.submitMove("H2", "H3");
    cg.submitMove("G4", "E3");
    cout << '\n';

    // 5. fxe3 Qh4+
    cg.submitMove("F2", "E3");
    cg.submitMove("D8", "H4");
    cout << '\n';

    // 6. g3 Qxg3#
    cg.submitMove("G2", "G3");
    cg.submitMove("H4", "G3");
    cout << '\n';


	cout<<endl;
	cout << "=========================\n";
    cout << "Sam Loyd's 10-Move Stalemate\n";
    cout << "=========================\n\n";

    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. e3 a5
    cg.submitMove("E2", "E3");
    cg.submitMove("A7", "A5");
    cout << '\n';

    // 2. Qh5 Ra6
    cg.submitMove("D1", "H5");
    cg.submitMove("A8", "A6");
    cout << '\n';

    // 3. Qxa5 h5
    cg.submitMove("H5", "A5");
    cg.submitMove("H7", "H5");
    cout << '\n';

    // 4. Qxc7 Rah6
    cg.submitMove("A5", "C7");
    cg.submitMove("A6", "H6");
    cout << '\n';

    // 5. h4 f6
    cg.submitMove("H2", "H4");
    cg.submitMove("F7", "F6");
    cout << '\n';

    // 6. Qxd7+ Kf7
    cg.submitMove("C7", "D7");
    cg.submitMove("E8", "F7");
    cout << '\n';

    // 7. Qxb7 Qd3
    cg.submitMove("D7", "B7");
    cg.submitMove("D8", "D3");
    cout << '\n';

    // 8. Qxb8 Qh7
    cg.submitMove("B7", "B8");
    cg.submitMove("D3", "H7");
    cout << '\n';

    // 9. Qxc8 Kg6
    cg.submitMove("B8", "C8");
    cg.submitMove("F7", "G6");
    cout << '\n';

    // 10. Qe6 (Stalemate)
    // The Black King is on g6. He is not in check.
    // The pawns are blocked. The Queen/Rook are trapped.
    cg.submitMove("C8", "E6");
    cout << '\n';

	cout << endl;
	cg.loadState("k7/8/8/8/4P3/5n2/8/K7 w -");
	cout << "=== checking pawns can't capture backwards ===\n";
	cg.submitMove("e4", "f3");

	cout << endl;
	cout << "=========================\n";
    cout << "Lasker vs. Thomas (1912)\n";
    cout << "=========================\n\n";

    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. d4 e6 2. Nf3 f5
    cg.submitMove("D2", "D4");
    cg.submitMove("E7", "E6");
    cg.submitMove("G1", "F3");
    cg.submitMove("F7", "F5");
    cout << '\n';

    // 3. Nc3 Nf6 4. Bg5 Be7
    cg.submitMove("B1", "C3");
    cg.submitMove("G8", "F6");
    cg.submitMove("C1", "G5");
    cg.submitMove("F8", "E7");
    cout << '\n';

    // 5. Bxf6 Bxf6 6. e4 fxe4
    cg.submitMove("G5", "F6");
    cg.submitMove("E7", "F6");
    cg.submitMove("E2", "E4");
    cg.submitMove("F5", "E4");
    cout << '\n';

    // 7. Nxe4 b6 8. Ne5 O-O
    cg.submitMove("C3", "E4");
    cg.submitMove("B7", "B6");
    cg.submitMove("F3", "E5");
    cg.submitMove("E8", "G8"); // Black Castles Short
    cout << '\n';

    // 9. Bd3 Bb7 10. Qh5 Qe7
    cg.submitMove("F1", "D3");
    cg.submitMove("C8", "B7");
    cg.submitMove("D1", "H5");
    cg.submitMove("D8", "E7");
    cout << '\n';

    // 11. Qxh7+!! Kxh7
    // The start of the King hunt
    cg.submitMove("H5", "H7");
    cg.submitMove("G8", "H7");
    cout << '\n';

    // 12. Nxf6+ Kh6
    // Double check (Knight and Bishop)
    cg.submitMove("E4", "F6");
    cg.submitMove("H7", "H6");
    cout << '\n';

    // 13. Neg4+ Kg5
    cg.submitMove("E5", "G4");
    cg.submitMove("H6", "G5");
    cout << '\n';

    // 14. h4+ Kf4
    cg.submitMove("H2", "H4");
    cg.submitMove("G5", "F4");
    cout << '\n';

    // 15. g3+ Kf3
    cg.submitMove("G2", "G3");
    cg.submitMove("F4", "F3");
    cout << '\n';

    // 16. Be2+ Kg2
    cg.submitMove("D3", "E2");
    cg.submitMove("F3", "G2");
    cout << '\n';

    // 17. Rh2+ Kg1
    cg.submitMove("H1", "H2"); // error - game thinks I'm in checkmate
    cg.submitMove("G2", "G1"); 
    cout << '\n';

    // 18. Kd2#
    // Discovered checkmate by the Rook on A1 (connected to H1 now)
    // Note: 18. O-O-O# was also legal, but Kd2 is the historic move
    cg.submitMove("E1", "D2");
    cout << '\n';

	cout << endl;
	cout << "=========================\n";
    cout << "Schulder vs. Boden (1853)\n";
    cout << "=========================\n\n";

    cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
    cout << '\n';

    // 1. e4 e5 2. Nf3 d6
    cg.submitMove("E2", "E4");
    cg.submitMove("E7", "E5");
    cg.submitMove("G1", "F3");
    cg.submitMove("D7", "D6");
    cout << '\n';

    // 3. c3 f5 4. Bc4 Nf6
    cg.submitMove("C2", "C3");
    cg.submitMove("F7", "F5");
    cg.submitMove("F1", "C4");
    cg.submitMove("G8", "F6");
    cout << '\n';

    // 5. d4 fxe4 6. dxe5 exf3
    cg.submitMove("D2", "D4");
    cg.submitMove("F5", "E4");
    cg.submitMove("D4", "E5");
    cg.submitMove("E4", "F3");
    cout << '\n';

    // 7. exf6 Qxf6 8. gxf3 Nc6
    cg.submitMove("E5", "F6");
    cg.submitMove("D8", "F6");
    cg.submitMove("G2", "F3");
    cg.submitMove("B8", "C6");
    cout << '\n';

    // 9. f4 Bd7 10. Be3 O-O-O
    // Black Castles Queenside (E8 -> C8)
    cg.submitMove("F3", "F4");
    cg.submitMove("C8", "D7");
    cg.submitMove("C1", "E3");
    cg.submitMove("E8", "C8"); 
    cout << '\n';

    // 11. Nd2 Re8 12. Qf3 Bf5
    cg.submitMove("B1", "D2");
    cg.submitMove("d8", "E8"); // Rook moves after castle
    cg.submitMove("D1", "F3");
    cg.submitMove("D7", "F5");
    cout << '\n';

    // 13. O-O-O d5
    // White Castles Queenside (E1 -> C1)
    cg.submitMove("E1", "C1"); 
    cg.submitMove("D6", "D5");
    cout << '\n';

    // 14. Bxd5 Qxc3+!!
    // Queen Sac
    cg.submitMove("C4", "D5");
    cg.submitMove("F6", "C3");
    cout << '\n';

    // 15. bxc3 Ba3#
    // Pawn takes Queen, Bishop mates
    cg.submitMove("B2", "C3");
    cg.submitMove("F8", "A3");
    cout << '\n';

	cout << endl;
	cout << "=== Checking castling (none should be valid) ===\n";
	cg.loadState("rnbqkbnr/ppppp1pp/8/8/8/8/PPPPP2P/RNBQK1bR w KQkq");
	cg.submitMove("e1", "g1");
	cg.loadState("rnbqkbnr/ppppp1pp/8/8/8/8/PPPPP2P/RNBQKb1R w KQkq");
	cg.submitMove("e1", "g1");
	cg.loadState("rnbqkbnr/ppppp1pp/8/8/5r2/8/PPPPP2P/RNBQK2R w KQkq");
	cg.submitMove("e1", "g1");
	cg.loadState("rnbqkbnr/ppppp1pp/8/8/6r1/8/PPPPP2P/RNBQK2R w KQkq");
	cg.submitMove("e1", "g1");


	return 0;
}