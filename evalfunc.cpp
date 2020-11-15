#include "evalfunc.h"

int EvalFunc::evaluate(char board[3][3]) //board is game board, function returns value based on who is winning, +1 is for x win, -1 is for o win, 0 is for draw 
{
	for (int row = 0; row < 3; row++) //checking if there is x or o win in any row 
	{
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) //if first check is passed it basically checks those with last one
		{
			if (board[row][0] == 'X')
				return 1;
			else if (board[row][0] == 'O') //else IF because it can be empty spot
				return -1;
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) //same as for rows
		{
			if (board[0][col] == 'X')
				return 1;
			else if (board[0][col] == 'O')
				return -1;
		}
	}

	//two ifs for diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			return 1;
		else if (board[0][0] == 'O')
			return -1;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
			return 1;
		else if (board[0][2] == 'O')
			return -1;
	}

	return 0; //if function hasnt returned any of above it is a draw
}