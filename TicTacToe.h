#pragma once
#include <iostream>
#include "optmove.h"

using namespace std;

#define SIDE 3 //lenght of the board
#define HUMAN 1 
#define COMPUTER 2

#define HUMANMOVE 'X' //player plays with X
#define COMPUTERMOVE 'O' //computer plays with O
//empty space is -

void showBoard(char board[SIDE][SIDE])
{
	cout << endl;
	cout << "   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
	cout << "  -----------" << endl;
	cout << "   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
	cout << "  -----------" << endl;
	cout << "   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
	cout << endl;
}

void showInstruction()
{
	cout << "Choose a cell number from 1 to 9 as below" << endl;
	
	char board[3][3] =
	{
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
	
	showBoard(board);
}

bool rowWin(char board[SIDE][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') //either X or O
			return true;
	}
	return false;
}

bool colWin(char board[SIDE][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
			return true;
	}
	return false;
}

bool diagWin(char board[SIDE][SIDE])
{
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
		return true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
		return true;
	return false;
}

int gameOver(char board[SIDE][SIDE])
{
	if (anyMoveLeft(board))
	{
		if (rowWin(board) || colWin(board) || diagWin(board))
			return 1;
		else
			return -1;
	}
	return 3;
}

void initialize(char board[SIDE][SIDE])
{
	for (int i = 0; i < SIDE; i++)
		for (int j = 0; j < SIDE; j++)
			board[i][j] = '-';
}

void humanMove(int cell, char board[SIDE][SIDE])
{
	switch (cell)
	{
	case 1:
	{
		if (board[0][0] = '-' && board[0][0] != 'O')
			board[0][0] = 'X';
	}
		break;
	case 2:
	{
		if (board[0][1] = '-' && board[0][1] != 'O')
			board[0][1] = 'X';
	}
	break;
	case 3:
	{
		if (board[0][2] = '-' && board[0][2] != 'O')
			board[0][2] = 'X';
	}
	break;
	case 4:
	{
		if (board[1][0] = '-' && board[1][0] != 'O')
			board[1][0] = 'X';
	}
	break;
	case 5:
	{
		if (board[1][1] = '-' && board[1][1] != 'O')
			board[1][1] = 'X';
	}
	break;
	case 6:
	{
		if (board[1][2] = '-' && board[1][2] != 'O')
			board[1][2] = 'X';
	}
	case 7:
	{
		if (board[2][0] = '-' && board[2][0] != 'O')
			board[2][0] = 'X';
	}
	break;
	case 8:
	{
		if (board[2][1] = '-' && board[2][1] != 'O')
			board[2][1] = 'X';
	}
	break;
	case 9:
	{
		if (board[2][2] = '-' && board[2][2] != 'O')
			board[2][2] = 'X';
	}
	break;
	default:
		break;
	}
}

void gameLoop()
{
	char board[SIDE][SIDE];
	initialize(board);
	int currentPlayer = 1;
	int cell;
	int res = -1;
	while (res != 1 && res != 0)
	{
		cout << "Current position" << endl;
		showBoard(board);
		if (currentPlayer == 1)
		{
			showInstruction();
			cin >> cell;
			humanMove(cell, board);
			currentPlayer = 2;
		}
		else
		{
			cout << "Computers turn" << endl;
			Move bestMove = findBestMove(board);
			board[bestMove.row][bestMove.col] = 'O';
			currentPlayer = 1;
		}
		res = gameOver(board);
	}
	if (res == 1)
	{
		if (currentPlayer == 2)
			cout << "Winner is X" << endl;
		else
			cout << "Winner is O" << endl;
	}
	else if (res == 3)
		cout << "It's a draw" << endl;
}