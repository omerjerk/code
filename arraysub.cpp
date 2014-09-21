#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <math.h>

#define LL long long

using namespace std;

inline void scan(LL *a) {
	register char c=0;
	while (c < 33)
		c = getchar();
	*a = 0;
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar();
	}
}
static void print(LL n) {
#define BSIZE 16
	char buf[BSIZE];
	LL bn = BSIZE-1;
	while (1) {
		buf[bn--] = '0'+(n%10);
		n = n / 10;
		if (n == 0) break;
	}
	while (bn<BSIZE-1) putchar(buf[++bn]);
	//putchar('\n');
}

class node {
    public :
        LL value;
        LL max;
};

// A utility function to get the middle index from corner indexes.
LL getMid(LL s, LL e) {  return s + (e -s)/2;  }
 
LL getMaxUtil(LL *st, LL ss, LL se, LL qs, LL qe, LL index)
{
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe) {
        return -2000000;
    }
 
    // If a part of this segment overlaps with the given range
    LL mid = getMid(ss, se);
    return max(getMaxUtil(st, ss, mid, qs, qe, 2*index+1),
           getMaxUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
LL getMax(LL *st, LL n, LL qs, LL qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
 
    return getMaxUtil(st, 0, n-1, qs, qe, 0);
}

LL constructSTUtil(LL arr[], LL ss, LL se, LL *st, LL si) {
    if (ss == se)
    {
        st[si] = arr[ss];
        //cout<<"(inside if) Derp with "<<st[si]<<endl<<" index = "<<si<<endl;
        return arr[ss];
    }
 
    LL mid = getMid(ss, se);
    //cout<<"Mid = "<<mid<<endl;
    st[si] =  max(constructSTUtil(arr, ss, mid, st, si*2+1), 
              constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
LL *constructST(LL arr[], LL n) {
    // Allocate memory for segment tree
    LL x = (LL)(ceil(log2(n))); //Height of segment tree
    LL max_size = 2*(LL)pow(2, x) - 1; //Maximum size of segment tree
    LL *st = new LL[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
/*
    for (LL i = 0; i < max_size; ++i) {
    	cout<<"Array index "<<i + 1<<" : "<<st[i]<<endl;
    }*/
 
    // Return the constructed segment tree
    return st;
}

int main() {
	LL N;
    LL K;
    scanf("%lld", &N);
    LL arr[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &arr[i]);
    }
    LL *st = constructST(arr, N);
    scanf("%lld", &K);
    for (int i = 0; i <= N - K; ++i) {
        printf("%lld ", getMax(st, N, i, i + K -1));
    }
    return 0;
}