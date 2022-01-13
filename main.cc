#include <iostream>
#include <stdexcept>
#include "sudoku.h"


int main() {

	std::cout << "Hello! Welcome to the Sudoku Solver!" << std::endl;
	std::cout << "Please enter the 81 entries of an empty Sudoku game. Missing entries should be 0" << std::endl;

	int newnum;
	int count = 0;
	int input[N*N];

	while (std::cin >> newnum) {

		if (count == 81) {
			break;
		}

		input[count] = newnum;
		++count;

	}

	if (count != 81) {
	
		std::cout << "Incorrect Number of Entries for Sudoku Game" << std::endl;
		std::cout << "Please enter 81 values" << std::endl;
		return 0;

	}

	Sudoku game{input};

	std::cout << "Old Sudoku: " << std::endl;
	std::cout << game << std::endl;
	std::cout << "Finished Sudoku: " << std::endl;
	game.solver();
	//if (game.done()) { // NO OTHER OPTION
		std::cout << game << std::endl;
	//} else {
	//	throw std::invalid_argument("DID NOT COMPLETE!!!");
	//}




}

