#include "sudoku.h"
#include <iostream>

Sudoku::Sudoku(const int * items) {

	// ASSUMING items has 81 items

	for (int i = 0; i < N; ++i) { // ROW

		for (int j = 0; j < N; ++j) { // COLUMN

			board[i][j] = items[i*N + j];

		}

	}
}

int Sudoku::getboard(const int i, const int j) const {
	return board[i][j];
}

std::ostream& operator<<(std::ostream& os, const Sudoku & game) {

	for (int i = 0; i < N; ++i) {
		
		os << "| ";
		for (int j = 0; j < N; ++j) {
			os << game.getboard(i, j) << " ";
		}
		os << "|" << std::endl;
	}

	return os;

}

bool Sudoku::legal(const int row, const int col, const int digit) const{

	for (int i = 0; i < N; ++i) {
		if (board[i][col] == digit) { return false; }
	}

	for (int j = 0; j < N; ++j) {
		if (board[row][j] == digit) { return false; }
	}

	for (int i = row - row % 3; i < row - row % 3 + 3; ++i) {
		
		for (int j = col - col % 3; j < col - col % 3 + 3; ++j) {
			if (board[i][j] == digit) { return false; }
		}

	}

	return true;

}

// IF BOARD IS DONE, WILL RETURN COORDS OFF THE BOARD
void Sudoku::findnext(int & row, int & col) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!board[i][j]) { 
				row = i;
			       	col = j;
			       	return; 
			}
		}
	}

	// IF you went through entire board without finding a 0 ->
	row = N;
	col = N;

}

bool Sudoku::done() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!board[i][j]) { return false; }
		}
	}

	return true;
}

// Now for the big one

bool Sudoku::solver() {

	int row = 0;
	int col = 0;

	findnext(row, col);

	if (row == N && col == N) {
		return true; // DONE
	}

	for (int n = 1; n < 10; ++n) {

		if (legal(row, col, n)) {

			board[row][col] = n;
			if (solver()) { return true; }
			else { board[row][col] = EMPTY; }

		}

	}

	return false;

}


