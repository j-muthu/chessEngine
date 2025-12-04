#include"ChessGame.h"

#include<iostream>

using std::cout;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessGame cg;
	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	cout << '\n';

	cg.submitMove("D7", "D6");
	cout << '\n';

	cg.submitMove("D4", "H6");
	cout << '\n';

	cg.submitMove("D2", "D4");
	cout << '\n';

	cg.submitMove("F8", "B4");
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	cout << '\n';

	cg.submitMove("E2", "E4");
	cg.submitMove("E7", "E6");
	cout << '\n';

	cg.submitMove("D2", "D4");
	cg.submitMove("D7", "D5");
	cout << '\n';

	cg.submitMove("B1", "C3");
	cg.submitMove("F8", "B4");
	cout << '\n';

	cg.submitMove("F1", "D3");
	cg.submitMove("B4", "C3");
	cout << '\n';

	cg.submitMove("B2", "C3");
	cg.submitMove("H7", "H6");
	cout << '\n';

	cg.submitMove("C1", "A3");
	cg.submitMove("B8", "D7");
	cout << '\n';

	cg.submitMove("D1", "E2");
	cg.submitMove("D5", "E4");
	cout << '\n';

	cg.submitMove("D3", "E4");
	cg.submitMove("G8", "F6");
	cout << '\n';

	cg.submitMove("E4", "D3");
	cg.submitMove("B7", "B6");
	cout << '\n';

	cg.submitMove("E2", "E6");
	cg.submitMove("F7", "E6");
	cout << '\n';

	cg.submitMove("D3", "G6");
	cout << '\n';

	cout << "------------------test-------------------------" << std::endl;

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");


	cg.submitMove("E2", "E4");
	cg.submitMove("F7", "F5");
	cg.submitMove("E4", "F5");
	cg.submitMove("G8", "F6");
	cg.submitMove("F1", "C4");
	cg.submitMove("E7", "E5");
	cg.submitMove("D1", "H5");
	cg.submitMove("F8", "E7");
	cout << std::endl << "^SHOULD NOT BE ALLOWED" << std::endl;

	cg.submitMove("G7", "G6");
	cg.submitMove("G1", "F3");
	cg.submitMove("F8", "C5");
	cg.submitMove("F3", "E5");
	cg.submitMove("E8", "G8");
	cout << std::endl << "^SHOULD NOT WORK : TRY TO CASTLE" << std::endl;

	cg.submitMove("G6", "G5");
	cout << std::endl << "^SHOULD NOT WORK: PINNED" << std::endl;

	cg.submitMove("C5", "E7");
	cg.submitMove("E5", "G6");
	cg.submitMove("D8", "D4");
	cout << std::endl<< "^SHOULD NOT BE ALLOWED: BLOCKED STRAIGHT" << std::endl;
	cg.submitMove("E7", "H4");
	cout << std::endl<< "^SHOULD NOT BE ALLOWED: BLOCKED DIAGONAL" << std::endl;



	cg.submitMove("E7", "F8");
	cg.submitMove("G6", "H8");
	cout << std::endl << "^SHOULD BE DISCOVERED CHECK" << std::endl;
	cg.submitMove("E8", "E7");
	cg.submitMove("E1", "G1");
	cout << std::endl << "^WHITE CASTLE" << std::endl;

	cg.loadState("5k2/8/6K1/3Q4/8/8/8/8 w -");
	cg.submitMove("D5", "E6");
	cout << std::endl << "^STALEMATE" << std::endl;

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	cg.submitMove("e2", "e4");
	cg.submitMove("e7", "e5");
	cg.submitMove("f1", "d3");
	cg.submitMove("d7", "d6");
	cg.submitMove("g1","f3");
	cg.submitMove("g8","h6");
	cg.submitMove("E1", "G1");
	
	return 0;
}
