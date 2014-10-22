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
void update_tree(int *tree, bool *lazy, int node, int a, int b, int i, int j) {


    if(i > j || a > j || b < i) // Current segment is not within range [i, j]
    {
    	if(lazy[node]) { // This node needs to be updated
		    tree[node] = b - a + 1 - tree[node]; // Update it
    
		    if(a != b) {
		    	//cout<<"Lazy node = "<<node;
		    	lazy[node*2] = !lazy[node*2]; // Mark child as lazy
		    	lazy[node*2+1] = !lazy[node*2+1]; // Mark child as lazy
		    }
    
		    lazy[node] = false; // Reset it
	    }
		return;
    }

  	if(a >= i && b <= j) { // Segment is fully within range
    	if (!lazy[node]) {
    		tree[node] = b - a + 1 - tree[node];

		    if(a != b) { // Not leaf node
		    	lazy[node*2] = !lazy[node*2];
		    	lazy[node*2+1] = !lazy[node*2+1];
		    }

	    }
	    lazy[node] = false;
    	return;
	}

	int mid = getMid(a, b);

	if(lazy[node]) { // This node needs to be updated
		    tree[node] = b - a + 1 - tree[node]; // Update it
    
		    if(a != b) {
		    	//cout<<"Lazy node = "<<node;
		    	lazy[node*2] = !lazy[node*2]; // Mark child as lazy
		    	lazy[node*2+1] = !lazy[node*2+1]; // Mark child as lazy
		    }
    
		    lazy[node] = false; // Reset it
	}

	update_tree(tree, lazy, node*2, a, mid, i, j); // Updating left child
	update_tree(tree, lazy, 1+(node*2), mid+1, b, i, j); // Updating right child

	tree[node] = tree[node*2] + tree[(node * 2) +1]; // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int *tree, bool *lazy, int node, int a, int b, int i, int j) {
	

    if (i > j || a > j || b < i) return 0;

	if(lazy[node]) { // This node needs to be updated
		tree[node] = b - a + 1 - tree[node]; // Update it

		if(a != b) {
			//cout<<"Lazy node = "<<node;
			lazy[node*2] = !lazy[node*2]; // Mark child as lazy
			lazy[node*2+1] = !lazy[node*2+1]; // Mark child as lazy
		}

		lazy[node] = false; // Reset it
	}

	if(a >= i && b <= j) {
		//cout<<"tree node = "<<node<<endl;
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

	int q1 = query_tree(tree, lazy, node*2, a, mid, i, j); // Query left child
	int q2 = query_tree(tree, lazy, 1+(node*2), mid + 1, b, i, j); // Query right child

	int res = q1 + q2; // Return final result
	
	return res;
}

int main() {
	//while (T--) {
		int N = scan_d();
		int M = scan_d();
		int derp = (int)(ceil(log2(N)));
		int max_size = 2*(int)pow(2, derp) - 1;
		//cout<<"max_size = "<<max_size<<endl;
		//int* arr = new int[N];
        int* tree = new int[max_size+1];
        bool* lazy = new bool[max_size+1];
		
		for(int i = 0; i < max_size+1; i++) {tree[i] = 0;
			lazy[i] = 0;}
		int option, x, y;
		for (int i = 0; i < M; ++i) {
			option = scan_d();
			switch(option) {
			    case 0 :
			        x = scan_d();
			        y = scan_d();
			        update_tree(tree, lazy, 1, 1, N, x, y);
			        //for (int j = 1; j < 10; ++j) {
			        //	cout<<"tree at "<<j<<" = "<<tree[j]<<"  ";
			        //}
			        //cout<<endl;
			        //for (int j = 1; j < 10; ++j) {
			        //	cout<<"lazy at "<<j<<" = "<<lazy[j]<<"  ";
			        //}
			        //cout<<endl;
			        break;
			    case 1:
			        x = scan_d();
			        y = scan_d();
			        println_d(query_tree(tree, lazy, 1, 1, N, x, y));
			        break;
		    }
		}
		delete[] tree;
		delete[] lazy;
	//}

	//update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	//update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	//update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	//cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}