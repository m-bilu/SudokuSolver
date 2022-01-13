#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

#define N 9
#define EMPTY 0

class Sudoku {

	int board[N][N];

  public:
	
	// Constructor
	Sudoku( const int * items);
	// Checks if adding some digit is legal. Does not modify board
	bool legal(const int row, const int col, const int digit) const;
	// Updates row and col coords with next missing spot, labelled 0 on board
	void findnext(int & row, int & col);
	// Returns true if no 0's are left on the board <-> board is complete
	bool done();
	// Recursively solves sudoku, returns true once all boxes have been solved
	bool solver();
	// Getter method
	int getboard(const int i, const int j) const;

};

std::ostream& operator<<(std::ostream& os, const Sudoku & game);

#endif
