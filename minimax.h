#pragma once
#include <bits.h>

using namespace std;

class MiniMax {

	//depth is the current depth of the tree
	//scores has all static evaluations
	//h is max height

private:
	int log2(int n);
public: 
	int minimax(int depth, int position, bool maximizingPlayer, int scores[], int h);
};