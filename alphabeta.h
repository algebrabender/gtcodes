#pragma once

#include <bits.h>

class AlphaBeta {
private:
	const int MAX = +10000;
	const int MIN = -10000;
public:
	int alphabeta(int depth, int position, bool maximizingPlayer, int scores[], int alpha, int beta, int h);
};