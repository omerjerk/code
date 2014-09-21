#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int R, C;
		scanf("%d", &R);
		scanf("%d", &C);
		int a[R][C];
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int  i = R - 1; i >= 0; --i) {
			for (int j = C - 1; j >= 0; --j) {
				int maxNum=0;
				if (i == R-1 && j == C-1)
					maxNum = 0;

				if (i == R-1 && j != C-1)
					maxNum = a[i][j+1];

				if (i != R-1 && j == C-1) 
					maxNum = a[i+1][j];

				if (i != R-1 && j != C-1)
					maxNum = max(a[i+1][j], a[i][j+1]);

				if (maxNum < 0) {
					a[i][j] += maxNum;
				}
			}
		}

		if (a[0][0] < 0)
			printf("%d\n", (a[0][0]* (-1)) + 1);
		else 
			printf("%d\n", 1);
	}
}