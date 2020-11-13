#pragma once

const int MAX = +10000;
const int MIN = -10000;

int alphabeta(int depth, int position, bool maximizingPlayer, int scores[], int alpha, int beta, int h)
{
	if (depth == h) //reached the leaf
	{
		return scores[position];
	}

	if (maximizingPlayer)
	{
		int best = MIN;

		for (int i = 0; i < 2; i++) //cant in one line like minimax bc of alpha and beta
		{
			int value = alphabeta(depth + 1, position * 2 + i, false, scores, alpha, beta, h);
			best = max(best, value);
			alpha = max(alpha, best);
			if (beta <= alpha) //cut off
				break;
		}

		return best;
	}

	else //minimizing player
	{
		int best = MAX;
		for (int i = 0; i < 2; i++)
		{
			int value = alphabeta(depth + 1, position * 2 + i, true, scores, alpha, beta, h);
			best = min(best, value);
			beta = min(beta, best);
			if (beta <= alpha) //cut off
				break;
		}

		return best;
	}
}