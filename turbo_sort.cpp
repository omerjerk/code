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
	int n, x;
	cin>>n;
	vector<int> list;
	while(n--) {
		scan(&x);
		list.push_back(x);
	}

	sort(list.begin(), list.end());
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it)
        print(*it);
	return 0;
}