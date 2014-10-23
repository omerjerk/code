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

struct query {
	int left, right, index;
};

bool cmpQuery (query L, query R) {
	if (L.right != R.right)
		return L.right < R.right;
	return L.left < R.left;
}

int getMid(int s, int e) {  return (e +s)/2;  }

/**
 * Build and init tree
 */
 /*
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}*/

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int *tree, int node, int a, int b, int x, int value) {

    if(a > x || b < x) {
		return;
    }

  	if(a == b) {
  		//cout<<"a = "<<a<<" x = "<<x<<" value = "<<value<<endl;
  		tree[node] = value;
    	return;
	}

	int mid = getMid(a, b);

	update_tree(tree, node*2, a, mid, x, value); // Updating left child
	update_tree(tree, 1+(node*2), mid+1, b, x, value); // Updating right child

	tree[node] = tree[node*2] + tree[(node * 2) +1]; // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int *tree, int node, int a, int b, int i, int j) {

    if (i > j || a > j || b < i) return 0;

	if (i <= a && b<= j) {
		//cout<<"returning with a = "<<a<<" b = "<<b<<endl;
		return tree[node];
	}// Current segment is totally within range [i, j]
		
    int mid = getMid(a, b);
	//cout<<"Mid = "<<mid<<endl;
	//cout<<"i = "<<i<<endl;
	//cout<<"j = "<<j<<endl;
	//if (i > mid)
	//	return query_tree(tree, lazy, (node*2) + 1, mid+1, b, i, j);
	//if (j <= mid)
	//	return query_tree(tree, lazy, node*2, a, mid, i, j);

	int q1 = query_tree(tree, node*2, a, mid, i, j); // Query left child
	int q2 = query_tree(tree, 1+(node*2), mid + 1, b, i, j); // Query right child
	
	return q1 + q2;
}

int main() {
	int N;
	N = scan_d();
	int source[N+1];
	int used[1000001] = {0};
	int tempSize = (int)(ceil(log2(N)));
	int max_size = 2*(int)pow(2, tempSize);
    int* tree = new int[max_size];
    for (int i = 0; i < max_size; ++i) {
    	tree[i] = 0;
    }
	for (int i = 1; i <= N; ++i) {
		source[i] = scan_d();
	}
	int Q = scan_d();
	query q[Q];
	int answer[Q];
	for (int i = 0; i < Q; ++i) {
		q[i].left = scan_d();
		q[i].right = scan_d();
		q[i].index = i;
	}
	sort(q, q + Q, cmpQuery);
	int j = 1;
	for (int i = 0; i < Q; ++i) {
		while (j <= q[i].right) {
			if (!used[source[j]]) {
				//cout<<" if value = "<<source[j]<<endl;
				update_tree(tree, 1, 1, N, j, 1);
				used[source[j]] = j;
			} else {
				//cout<<" else value = "<<source[j]<<endl;
				update_tree(tree, 1, 1, N, used[source[j]], 0);
				update_tree(tree, 1, 1, N, j, 1);
				used[source[j]] = j;
			}
			++j;
		}
		//for(int k = 1; k < max_size; ++k) {
		//	cout<<tree[k]<<"\t";
		//}
		//cout<<endl;
		answer[q[i].index] = query_tree(tree, 1, 1, N, q[i].left, q[i].right);
		//println_d(answer[q[i].index]);
	}
	for (int i = 0; i < Q; ++i) {
		println_d(answer[i]);
	}
}