/*
Author:			Michael Garod
Created on:		2/1/15
File:			Header.h
Title:			8-Queens
Description:	Contains declaration for class Board
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class Board
{
	public:
		Board();
		Board(const int);
		void clearBoard();
		const void printBoard();
		void calculateArrangements(int, int&);

	private:
		int rows;
		int cols; // abbreviation for columns
		char** gameBoard; // upon Board(int, int), this becomes char[i][j];

		// Private Functions
		void placeQueen(const int, const int);
		void removeQueen(const int, const int);
		bool checkDeadZone(const int, const int);
};

#endif