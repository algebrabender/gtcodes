#include "minimax.h"
#include <iostream>

int main()
{
	int scores[] = { 3, 5, 2, 9, 12, 5, 23, 23 };
	int n = sizeof(scores) / sizeof(scores[0]);
	int h = log2(n);
	int max = minimax(0, 0, true, scores, h);
	cout << "The optimal value if maximizing is starting first is: " << max << endl;
	int min = minimax(0, 0, false, scores, h);
	cout << "The optimal value if minimazing is starting first is: " << min << endl;
	const int MAX = +10000;
	const int MIN = -10000;
	int scoresAB[] = { 3, 5, 6, 9, 1, 2, 0, -1 };
	int nAB = sizeof(scoresAB) / sizeof(scoresAB[0]);
	int hAB = log2(nAB);
	int alphabetaMax = alphabeta(0, 0, true, scoresAB, MAX, MIN, hAB);
	cout << "The optimal value if maximizing is starting first is: " << alphabetaMax << endl;
	int alphabetaMin = alphabeta(0, 0, false, scoresAB, MAX, MIN, hAB);
	cout << "The optimal value if minimizing is starting first is: " << alphabetaMin << endl;
}
