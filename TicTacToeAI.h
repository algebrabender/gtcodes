#pragma once
#include "TicTacToe.h"
#include "evalfunc.h"
#include <vector>

struct AIMove {
	AIMove() {};
	AIMove(int score) : score(score), row(-1), col(-1){};
	int row;
	int col;
	int score;
};

AIMove getBestMove(char board[SIDE][SIDE], bool computerMove) //minimax
{ 
	//ending recursion 
	int rv = evaluate(board);
	if (rv == -1)
		return AIMove(10);
	else if (rv == 1)
		return AIMove(-10);
	else if (!anyMoveLeft(board))
		return AIMove(0);

	vector<AIMove> moves;
	
	//recursion and moves vector
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (board[i][j] == '-')
			{
				AIMove move;
				move.row = i;
				move.col = j;
				if (computerMove)
				{
					board[i][j] = 'O';
					move.score = getBestMove(board, !computerMove).score;
				}
				else
				{
					board[i][j] = 'X';
					move.score = getBestMove(board, !computerMove).score;
				}
				moves.push_back(move);
				board[i][j] = '-';
			}
		}
	}
	
	//finding best move for computer
	int bestMove = 0;
	if (computerMove)
	{
		int bestScore = -100000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else
	{
		int bestScore = 100000;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i].score < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	//returns best move
	return moves[bestMove];
}

void performMove(char board[SIDE][SIDE])
{
	AIMove bestMove = getBestMove(board, true);
	board[bestMove.row][bestMove.col] = 'O';
}