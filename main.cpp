/*
Author:			Michael Garod
Created on:		2/1/15
File:			main.cpp
Title:			8-Queens
Description:	http://en.wikipedia.org/wiki/Eight_queens_puzzle
				On any NxN chessboard, find and count every possible way to
				place N queens (the maximum number of queens) without
				allowing them to collide according to the rules of Chess.
*/

#include "Header.h"
#include <ctime>

int main()
{
	unsigned long start_time = time(NULL);

	Board aBoard(8);

	int number_of_arrangements = 0;

	aBoard.calculateArrangements(0, number_of_arrangements);

	cout << number_of_arrangements << endl;

	// Displays seconds elapsed since start
	cout << time(NULL) - start_time << endl;

	return 0;
}