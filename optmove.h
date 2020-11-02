#pragma once
#include "evalfunc.h"
#include <iostream>

using namespace std;

//code for function that fins the next optimal move for a player in tic tac toe game

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'y';

bool anyMoveLeft(char board[3][3]) //function that checks if there is any moves left
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == '-')
				return true;
	return false; //if function havent returned in any iteration there is no moves left
}

int minimax(char board[3][3], int depth, bool maximazingPlayer) //minimax funtion where maximazingPlayer is X
{
	int score = evaluate(board);

	if (score == 1 or score == -1) //if game is finished and maximaxingPlayer/X has won or O has won 
		return score;
	
	if (!anyMoveLeft(board)) //if there was a draw (maybe can be done with just score)
		return 0;

	if (maximazingPlayer) //if it is X's turn
	{
		int best = -10000;

		for (int i = 0; i < 3; i++) //going every cell
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '-') //if cell is empty
				{
					board[i][j] = player; //making the move
					best = max(best, minimax(board, depth + 1, !maximazingPlayer)); //to choose best value
					board[i][j] = '-';
				}
			}
		}
		return best;
	}

	else //if it is O's turn
	{
		int best = 10000;

		for (int i = 0; i < 3; i++) //going every cell
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '-') //if cell is empty
				{
					board[i][j] = opponent; //making the move
					best = min(best, minimax(board, depth + 1, !maximazingPlayer)); //to choose best value
					board[i][j] = '-';
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[3][3]) //function that finds the best possible move for player with given board situation
{
	int bestVal = -10000;
	Move bestMove;
	bestMove.col = -1;
	bestMove.row = -1;

	for (int i = 0; i < 3; i++) //going every cell
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '-') //if cell is empty
			{
				board[i][j] = player; //making the move
				int moveVal = minimax(board, 0, false); //evaluates this move
				board[i][j] = '-';
				
				if (moveVal > bestVal) //if making the move would give better result we upadte that to be best move
				{
					bestMove.col = j;
					bestMove.row = i;
					bestVal = moveVal;
				}
			}
		}
	}

	cout << "The value of the best Move is: " << bestVal << endl;
	
	return bestMove;
}