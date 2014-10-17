#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <locale>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <string>
using namespace std;


//end of header files

#define ONLINE_JUDGE

#define llu long long unsigned
#define lld long long
#define ld long
//end of definitions
//#ifndef ONLINE_JUDGE
#define getchar_unlocked() getchar()
#define putchar_unlocked(x) putchar(x)
//#endif // ONLINE_JUDGE

#define MAX_NUM 1000000

int scan_d()    {register int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {register int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {register int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {register int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

//fast output

//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//special char
char sp='/';
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

inline void scan(string &ret){
    register int a=getchar_unlocked();
    ret="";
    while(a==' '||a=='\n'||a==EOF)
        a=getchar_unlocked();
    while(a!=' '&&a!='\n'&&a!=EOF){
        ret+=(char)a;
        a=getchar_unlocked();
    }
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int editDistance (string s, string w, int a, int b, int k) {
	int m = s.length();
	int n = w.length();

	if (a == 0) {
		return 0;
	}
	
	if (abs(m - n) > k) {
		return -1;
	}
	//int v1[m+1], v0[m+1];

	int* v1 = new int[m+1];
	int* v0 = new int[m+1];

	for (int i = 0; i <= m; ++i)
		v0[i] = i*a;

	int left_cell, top_cell, corner_cell;

	for (int i = 1; i <= n; ++i) {
		v1[0] = v0[0] + a;
		for (int j = max(i-k + 1, 1); j <= min(i + k + 1, m); ++j) {
			//cout<<"first = "<<i - k +1<<" ";
			if (w[i-1] == s[j-1]) {
				//cout<<"i = "<<i<<" j = "<<j<<"\t";
				v1[j] = v0[j-1];
			} else {
				corner_cell = v0[j-1] + b;
				if (j != (i-k+1))
					left_cell = v1[j-1] + a;
			    else
			    	left_cell = MAX_NUM;
			    
			    if (j != (i + k + 1))
			        top_cell = v0[j] + a;
			    else
			    	top_cell = MAX_NUM;
			    v1[j] = min(min(left_cell, top_cell), corner_cell);
			   
			}
			 //cout<<"v1["<<j<<"] = "<<v1[j]<<"\t";
		}
		//cout<<endl;
		int* temp = v0;
		v0 = v1;
		v1 = temp;
	}
	int ans = v0[m];
	delete[] v1;
	delete[] v0;
	if (ans > k) ans = -1;
	return ans;
}

int main() {
	int T;
	T = scan_d();
	while (T--) {
		string s, w;
		scan(s); scan(w);
		//sLength = s.length();
		//wLength = w.length();
		int a, b, k;
		a = scan_d();
		b = scan_d();
		k = scan_d();

		print_d(editDistance(s, w, a, b, k));
		putchar('\n');
	}
}