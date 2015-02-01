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

int main()
{
	Board aBoard(10);

	int count = 0;

	aBoard.calculateArrangements(0, count);

	cout << count << endl;

}