#pragma once
#include "evalfunc.h"
#include <iostream>

using namespace std;

//code for function that finds the next optimal move for a player in tic tac toe game

class OptMove {
private: 
	struct Move
	{
		int row, col;
	};
	char player = 'O', opponent = 'X';
	EvalFunc func;
public:
	bool anyMoveLeft(char board[3][3]);
	int minimax(char board[3][3], int depth, bool maximazingPlayer);
	Move findBestMove(char board[3][3]);
};