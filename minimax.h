#pragma once
#include <bits.h>

using namespace std;

//depth is the current depth of the tree
//scores has all static evaluations
//h is max height

int minimax(int depth, int position, bool maximizingPlayer, int scores[], int h)
{
	if (depth == h) //reached the leaf
	{
		return scores[position];
	}

	if (maximizingPlayer)
	{
		return max(minimax(depth + 1, position * 2, false, scores, h), minimax(depth + 1, position * 2 + 1, false, scores, h)); //postions is like heap
	}

	else //minimizing player
	{
		return min(minimax(depth + 1, position * 2, true, scores, h), minimax(depth + 1, position * 2 + 1, true, scores, h));
	}
}

int log2(int n)
{
	return (n == 1) ? 0 : 1 + log2(n / 2);
}