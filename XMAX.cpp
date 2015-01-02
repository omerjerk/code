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
	//int T;
	//T = s_d();
	//while (T--) {
		int N, K;
		N = s_d();
		//K = s_d();
		vector<llu> a;
		llu x;
		for (int i = 0; i < N; ++i) {
			x = s_llu();
			a.push_back(x);
		}
		//a.push_back(K);
		//++N;
		sort(a.rbegin(),a.rend());
		/*
		for (int i = 0; i < a.size(); ++i) {
			cout<<" "<<a[i];
		} cout<<endl; */
		llu sig=1;
        int bitCount = 0;
        while(sig<=a[0]) {
            ++bitCount;
            sig<<=1;
        }
       
        sig>>=1;
        
        for(int t=0;sig>=1;sig>>=1) {
             int i=t;
             
             while(i<N && (a[i]&sig)==0)
             i++;
             
             if(i>=N)
             continue;
             
             swap(a[t],a[i]);
             
             for(int j=0;j<N;++j) {
                 if(j!=t && (a[j]&sig)!=0)
                 a[j]=a[j]^a[t];
             }
             ++t;
        }
/*
        for (int i = 0; i < N; ++i) {
        	cout<<" "<<a[i];
        } cout<<endl;
  */      
        llu result=0;
        sig = 1;
        for (int i = 0; i < bitCount; ++i) {
            sig<<=1;
        }
        sig>>=1;
        for(int q=0;q<N && q < bitCount;q++) {
                if ((a[q]&sig) != 0) {
                result=result^a[q];
                sig >>= 1;
            }
        }
        pln_llu(result);
	//}
}