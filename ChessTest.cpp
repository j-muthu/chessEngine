#include"ChessGame.h"

#include<iostream>

using std::cout;
using std::endl;

int main() {	
	ChessGame cg;

	cout << "================== TEST ==================" << endl;

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");


	cg.submitMove("E2", "E4");
	cg.submitMove("F7", "F5");
	cg.submitMove("E4", "F5");
	cg.submitMove("G8", "F6");
	cg.submitMove("F1", "C4");
	cg.submitMove("E7", "E5");
	cg.submitMove("D1", "H5");
	cg.submitMove("F8", "E7");
	cout << endl << "^SHOULD NOT BE ALLOWED" << endl;

	cg.submitMove("G7", "G6");
	cg.submitMove("G1", "F3");
	cg.submitMove("F8", "C5");
	cg.submitMove("F3", "E5");
	cg.submitMove("E8", "G8");
	cout << endl << "^SHOULD NOT WORK : TRY TO CASTLE" << endl;

	cg.submitMove("G6", "G5");
	cout << endl << "^SHOULD NOT WORK: PINNED" << endl;

	cg.submitMove("C5", "E7");
	cg.submitMove("E5", "G6");
	cg.submitMove("D8", "D4");
	cout << endl<< "^SHOULD NOT BE ALLOWED: BLOCKED STRAIGHT" << endl;
	cg.submitMove("E7", "H4");
	cout << endl<< "^SHOULD NOT BE ALLOWED: BLOCKED DIAGONAL" << endl;



	cg.submitMove("E7", "F8");
	cg.submitMove("G6", "H8");
	cout << endl << "^SHOULD BE DISCOVERED CHECK" << endl;
	cg.submitMove("E8", "E7");
	cg.submitMove("E1", "G1");
	cout << endl << "^WHITE CASTLE" << endl;

	cg.loadState("5k2/8/6K1/3Q4/8/8/8/8 w =");
	cg.submitMove("D5", "E6");
	cout << endl << "^STALEMATE" << endl;

	cg.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	cg.submitMove("e2", "e4");
	cg.submitMove("e7", "e5");
	cg.submitMove("f1", "d3");
	cg.submitMove("d7", "d6");
	cg.submitMove("g1","f3");
	cg.submitMove("g8","h6");
	cg.submitMove("E1", "G1");
    cout << "^testing castling" << endl;

	cout << endl;
    cg.loadState("rnbqkbnr/ppppppp1/p7/8/8/8/PPPPPPPP/RNBQKBNR b KQkq");
    cg.submitMove("a6", "a4");
    cg.submitMove("g7", "g5");
    cout << "^initialising a board with pawn out of place to check it can't"
    << " advance 2 spaces" << endl << endl;

	return 0;
}