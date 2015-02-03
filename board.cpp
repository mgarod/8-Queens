/*
Author:			Michael Garod
Created on:		2/1/15
File:			board.cpp
Title:			8-Queens
Description:	Contains implementation for class Board
*/

#include "Header.h"

/*** Public Functions ***/
Board::Board() {}

//Pre:	Accepts a number N to be used to construct the NxN gameBoard.
//		The gameBoard is a dynamic 2D character array
//Post:	The gameBoard is set and cleared by clearBoard()
Board::Board(const int in_rows)
{	
	rows = in_rows;
	cols = rows;
	gameBoard = new char*[rows];

	for (int i = 0; i < in_rows; i++)
	{
		gameBoard[i] = new char[cols];
	}

	clearBoard();
}

//Pre:	n/a
//Post:	Sets all spaces on the board to ' '
void Board::clearBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			gameBoard[i][j] = ' ';
		}
	}
}

//Pre:	n/a
//Post:	Prints to console the current gameBoard
const void Board::printBoard()
{
	// This formula represents the maximum number of monospaces
	// required to fulfill any gameBoard with N columns
	int width = (2 * cols) + 1;

	// Top horizontal
	for (int i = 0; i < width; i++)
	{
		if (i < (width - 1) )
		{	
			cout << "-";
		}
		else if (i == (width - 1) )
		{
			cout << "-\n";
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (0 == j)
			{	// left vertical divider only on first entry
				cout << "|" << gameBoard[i][j] << "|";
			}
			else if (j == (cols - 1) )
			{	// newline after right vertical divider only on final entry
				cout << gameBoard[i][j] << "|\n";
			}
			else
			{ // right vertical divider after middle entries
				cout << gameBoard[i][j] << "|";
			}
		}
		
		// Horizontal divider between rows and bottom horizontal
		for (int i = 0; i < width; i++)
		{
			if (i < width - 1)
			{
				cout << "-";
			}
			else
			{
				cout << "-\n";
			}
		}
	}
	cout << endl;
}

//Description:	Method uses backtracking to calculate all valid arrangements.
//		When a Queen is placed, it is impossible to place another Queen on
//		the same row, therefore skip immediately to the next row.
//Pre:	First use assumes current_row to be 0, and count to be 0.
//Post:	gameBoard will contain whatever the final found
//		arragement was when recursion ended.
void Board::calculateArrangements(int current_row, int& count)
{
	for (int j = 0; j < cols; j++)
	{
		if ( checkDeadZone(current_row, j) && (current_row == (rows-1)) )
		{	// Place last Queen, print, count, backtrack
			placeQueen(current_row, j);
			printBoard();
			count++;
			removeQueen(current_row, j);
		}
		else if ( checkDeadZone(current_row, j) )
		{	// Place Queen, skip to next row, recur, backtrack
			placeQueen(current_row, j);
			// No 2 queens can be in the same row, so just skip to next row
			calculateArrangements(current_row + 1, count);
			removeQueen(current_row, j);
		}
	}
}

/*** Private Functions ***/

// Used only by calculateArrangements();
void Board::placeQueen(const int i, const int j)
{
	gameBoard[i][j] = 'Q';
}

// Used only by calculateArrangements();
void Board::removeQueen(const int i, const int j)
{
	gameBoard[i][j] = ' ';
}

//Pre:	Accepts arguments for row and column. This is the proposed
//		tile to place the next Queen.
//Post: Returns true if the proposed tile a valid tile to place a Queen 
//		according to the rules of chess Queens. Returns false if illegal.
bool Board::checkDeadZone(const int Q_row, const int Q_col)
{
	// Setting mutable vars (i,j) while keeping Queen's position const
	int i = Q_row;
	int j = Q_col;

	// If the space is occupied with anything, do not place Queen
	if (gameBoard[i][j] != ' ')
	{
		return false;
	}

	// Up is calculated ASAP to increase efficiency
	// because no 2 queens can be in the same column
	while (i > 0)
	{
		i--;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	// Up & Left
	while (i > 0 && j > 0)
	{
		i--;
		j--;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	// Up & Right
	while (i > 0 && j < cols - 1)
	{
		i--;
		j++;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	/*		Checking for collisions that are impossible

	// Down
	while (i < rows - 1)
	{
		i++;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	// Left
	while (j > 0)
	{
		j--;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	// Right
	while (j < cols - 1)
	{
		j++;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position


	// Down & Left
	while (i < rows - 1 && j > 0)
	{
		i++;
		j--;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}

	i = Q_row; j = Q_col; // Reset to Queen's Position

	// Down & Right
	while (i < rows - 1 && j < cols - 1)
	{
		i++;
		j++;
		if (gameBoard[i][j] == 'Q')
		{
			return false;
		}
	}
	*/

	// If no collision found, then it is safe to place the queen at (i,j)
	return true;
}
