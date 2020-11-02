#pragma once
#include <algorithm>

using namespace std;

//code for evaluation funcion used in tic tac toe game

int evaluate(char ttt[3][3]) //ttt is game board, function returns value based on who is winning, +1 is for x win, -1 is for o win, 0 is for draw 
{
	for (int row = 0; row < 3; row++) //checking if there is x or o win in any row 
	{
		if (ttt[row][0] == ttt[row][1] && ttt[row][1] == ttt[row][2]) //if first check is passed it basically checks those with last one
		{
			if (ttt[row][0] == 'x')
				return 1;
			else if (ttt[row][0] == 'o') //else IF because it can be empty spot
				return -1;
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (ttt[0][col] == ttt[1][col] && ttt[1][col] == ttt[2][col]) //same as for rows
		{
			if (ttt[0][col] == 'x')
				return 1;
			else if (ttt[0][col] == 'o')
				return -1;
		}
	}

	//two ifs for diagonals
	if (ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2])
	{
		if (ttt[0][0] == 'x')
			return 1;
		else if (ttt[0][0] == 'o')
			return -1;
	}

	if (ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0])
	{
		if (ttt[0][2] == 'x')
			return 1;
		else if (ttt[0][2] == 'o')
			return -1;
	}

	return 0; //if function hasnt returned any of above it is a draw
}