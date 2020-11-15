#pragma once
#include <algorithm>

using namespace std;

//code for evaluation funcion used in tic tac toe game

class EvalFunc {
public:
	int evaluate(char board[3][3]);
};