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
	int N, Q;
	N = s_d();
	Q = s_d();
	int a[N];
	for (int i = 0;i < N; ++i) {
		a[i] = s_d();
	}

	int m;
	int l,r;
	int key;

    bool flag = false;

	for (int i = 0; i < Q; ++i) {
		l = 0;
	    r = N-1;
		key = s_d();
		flag = false;
		while (l <= r) {
			m = l + (r-l)/2;
			if (a[m] == key) {
				flag = true;
				while (m != 0 && a[m-1] == a[m]) {
					--m;
				}
				break;
			} else if (a[m] < key) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		if (flag) {
			pln_d(m);
		} else {
			pln_d(-1);
		}		
	}
}
