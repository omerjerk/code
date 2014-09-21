#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <map>

#define LL long long

using namespace std;

inline void scan(unsigned int *a) {
	register char c=0;
	while (c < 33)
		c = getchar();
	*a = 0;
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar();
	}
}
static void print(unsigned int n) {
#define BSIZE 16
	char buf[BSIZE];
	int bn = BSIZE-1;
	while (1) {
		buf[bn--] = '0'+(n%10);
		n = n / 10;
		if (n == 0) break;
	}
	while (bn<BSIZE-1) putchar(buf[++bn]);
	//putchar('\n');
}

map<unsigned int, unsigned int> memory;

unsigned int findMaxConversion(unsigned int input) {
	if (input == 0) return 0;
	if (memory[input]) return memory[input];
	unsigned int X = findMaxConversion(input/2);
	unsigned int Y = findMaxConversion(input/3);
	unsigned int Z = findMaxConversion(input/4);

    
    unsigned int sum = X + Y + Z;
	if (sum > input) {
		memory[input] = sum;
		return sum;
	} else {
		memory[input] = input;
		return input;
	}
}

int main() {
	unsigned int N;
	while(scanf("%ud\n",&N)!=EOF) {
		N = findMaxConversion(N);
		print(N);
		putchar('\n');
	}
}