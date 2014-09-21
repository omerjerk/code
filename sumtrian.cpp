#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>

using namespace std;
inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar();
	*a = 0;
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar();
	}
}
static void print(int n) {
#define BSIZE 16
	char buf[BSIZE];
	int bn = BSIZE-1;
	while (1) {
		buf[bn--] = '0'+(n%10);
		n = n / 10;
		if (n == 0) break;
	}
	while (bn<BSIZE-1) putchar(buf[++bn]);
	putchar('\n');
}

int main() {
    int N, size;
    int temp;
    scan(&N);
    while (N--) {
    	scan(&size);
    	int a[size+1][size+1];
        for (int i = 0; i<size; ++i) {
    	    for(int j = 0; j <= i ; ++j) {
    		    scan(&temp);
        		a[i][j] = temp;
        	}
        }

        for (int i = size - 1; i >= 0; --i) {
    	    for (int j = 0; j <= i; ++j) {
    		    a[i-1][j] += (a[i][j] > a[i][j+1] ? a[i][j] : a[i][j+1]);
    	    }
        }

        print(a[0][0]);
    }
    
}