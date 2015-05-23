#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define llu long long unsigned

#ifndef ONLINE_JUDGE
#define getchar_unlocked() getchar()
#define putchar_unlocked(x) putchar(x)
#endif // ONLINE_JUDGE

int s_d()    {register int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu s_llu()    {register int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

void pln_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void pln_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

int main() {
	int N = -1;
	int M = -1;
	while (true) {
		N = s_d();
		M = s_d();
		int a[501][501];
		int b[501][501];
		if (N == 0 && M == 0) break;
		int sum[2][501][501];
		int dp[501][501];

		for (int i = 0; i < 501; ++i) {
			sum[0][0][i] = 0;
			sum[1][i][0] = 0;
			dp[0][i] = 0;
			dp[i][0] = 0;
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				a[i][j] = s_d();
				sum[1][i][j] = sum[1][i][j-1] + a[i][j];
			}
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				b[i][j] = s_d();
				sum[0][i][j] = sum[0][i-1][j] + b[i][j];
			}
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				dp[i][j] = max(dp[i][j-1] + sum[0][i][j], dp[i-1][j] + sum[1][i][j]);
			}
		}
		pln_d(dp[N][M]);
	}
}
