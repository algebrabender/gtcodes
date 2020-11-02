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
}