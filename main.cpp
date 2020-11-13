#include "minimax.h"
#include "alphabeta.h"
#include "evalfunc.h"
#include "optmove.h"
#include "TicTacToeAI.h"

int main()
{
	/*int scores[] = { -49, 17, -90, -21, 18, -32, -8, 7, 3, -92, 61, 87, 13, 40, -15, 36, 19, 33, 66, 40, 84, 56, -75, -7, 61  };
	int n = sizeof(scores) / sizeof(scores[0]);
	int h = log2(n);
	int max = minimax(0, 0, true, scores, h);
	cout << "The optimal value if maximizing is starting first is: " << max << endl;
	int min = minimax(0, 0, false, scores, h);
	cout << "The optimal value if minimazing is starting first is: " << min << endl;
		const int MAX = +10000;
	const int MIN = -10000;
	int scoresAB[] = { -49, 17, -90, -21, 18, -32, -8, 7, 3, -92, 61, 87, 13, 40, -15, 36, 19, 33, 66, 40, 84, 56, -75, -7, 61 };
	int nAB = sizeof(scoresAB) / sizeof(scoresAB[0]);
	int hAB = log2(nAB);
	int alphabetaMax = alphabeta(0, 0, true, scoresAB, MIN, MAX, hAB);
	cout << "The optimal value if maximizing is starting first is: " << alphabetaMax << endl;
	int alphabetaMin = alphabeta(0, 0, false, scoresAB, MIN, MAX, hAB);
	cout << "The optimal value if minimizing is starting first is: " << alphabetaMin << endl;
	
	cout << "----------------------------------------------------------" << endl;
	
	//tic tac toe
	char board[3][3] =
	{
		{'x', 'o', 'x'},
		{'o', 'o', 'x'},
		{'-', '-', '-'}
	};

	int value = evaluate(board);
	if (value == 1)
		cout << "The winner is X" << endl;
	else if (value == -1)
		cout << "The winner is O" << endl;
	else
		cout << "Draw" << endl;

	cout << "----------------------------------------------------------" << endl;

	Move bestMove = findBestMove(board);
	
	cout << "The optimal move is: " << endl;
	cout << "ROW: " << bestMove.row << " COL: " << bestMove.col << endl;

	board[bestMove.row][bestMove.col] = 'x';

	for (int i = 0; i < 3; i++) //going every cell
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << endl;
	}*/

	char board[SIDE][SIDE];
	initialize(board);
	int currentPlayer = 1;
	int cell;
	int res = -1;
	while (res != 3)
	{
		cout << "Current state of board" << endl;
		showBoard(board);
		if (currentPlayer == 1)
		{
			showInstruction();
			cin >> cell;
			cout << endl;
			humanMove(cell, board);
			currentPlayer = 2;
		}
		else
		{
			cout << "Computers turn" << endl;
			performMove(board);
			currentPlayer = 1;
		}
		res = gameOver(board);
	}
	showBoard(board);
	if (res == 1)
	{
		if (currentPlayer == 2)
			cout << "Winner is X" << endl;
		else
			cout << "Winner is O" << endl;
	}
	else
		cout << "It's a draw" << endl;

	return 0;
}