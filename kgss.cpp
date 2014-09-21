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

class Node {
    public :
        LL maxSum;
        LL maxNum;
};

// A utility function to get the middle index from corner indexes.
LL getMid(LL s, LL e) {  return s + (e -s)/2;  }
 
Node getMaxUtil(Node *st, LL ss, LL se, LL qs, LL qe, LL index)
{
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe) {
    	Node tempNode;
    	tempNode.maxSum = tempNode.maxNum = 0;
        return tempNode;
    }
 
    // If a part of this segment overlaps with the given range
    LL mid = getMid(ss, se);
    Node left = getMaxUtil(st, ss, mid, qs, qe, 2*index+1);
    Node right = getMaxUtil(st, mid+1, se, qs, qe, 2*index+2);
    Node nodeToReturn;
    nodeToReturn.maxSum = left.maxSum > right.maxSum ? left.maxSum : right.maxSum;
    nodeToReturn.maxNum = left.maxNum > right.maxNum ? left.maxNum : right.maxNum;
    LL tempSum = left.maxNum + right.maxNum;
    if (tempSum > nodeToReturn.maxSum) nodeToReturn.maxSum = tempSum;
    return nodeToReturn;
}
 
Node getMax(Node *st, LL n, LL qs, LL qe) { 
    return getMaxUtil(st, 0, n-1, qs, qe, 0);
}

/* A recursive function to update the nodes which have the given index in
   their range. The following are parameters
    st, index, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(Node *st, LL ss, LL se, LL i, LL newVal, LL index) {
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

    if (se != ss) {
        LL mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, newVal, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, newVal, 2*index + 2);
        LL leftIndex = 2*index + 1; LL rightIndex = 2*index + 2;
        st[index].maxSum = st[leftIndex].maxSum > st[rightIndex].maxSum ? st[leftIndex].maxSum : st[rightIndex].maxSum;
        st[index].maxNum = st[leftIndex].maxNum > st[rightIndex].maxNum ? st[leftIndex].maxNum : st[rightIndex].maxNum;
        LL tempSum = st[leftIndex].maxNum + st[rightIndex].maxNum;
        if (tempSum > st[index].maxSum) st[index].maxSum = tempSum;
    } else {
    	st[index].maxNum = st[index].maxSum = newVal;
    }
}

void updateValue(Node *st, LL n, LL i, LL new_val) {
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, new_val, 0);
}

Node constructSTUtil(Node arr[], LL ss, LL se, Node *st, LL si) {
    if (ss == se) {
        st[si] = arr[ss];
        //cout<<"(inside if) Derp with "<<st[si]<<endl<<" index = "<<si<<endl;
        return arr[ss];
    }
 
    LL mid = getMid(ss, se);
    Node left = constructSTUtil(arr, ss, mid, st, si*2+1);
    Node right = constructSTUtil(arr, mid+1, se, st, si*2+2);
    st[si].maxSum = left.maxSum > right.maxSum ? left.maxSum : right.maxSum;
    st[si].maxNum = left.maxNum > right.maxNum ? left.maxNum : right.maxNum;
    LL tempSum = left.maxNum + right.maxNum;
    if (tempSum > st[si].maxSum) st[si].maxSum = tempSum;
    return st[si];
}
 
Node *constructST(LL arr[], LL n) {
    // Allocate memory for segment tree
    LL x = (LL)(ceil(log2(n))); //Height of segment tree
    LL max_size = 2*(LL)pow(2, x) - 1; //Maximum size of segment tree
    Node *st = new Node[max_size];
    Node inputArray[n];
    for (LL i = 0; i < n; ++i) {
    	inputArray[i].maxSum = inputArray[i].maxNum = arr[i];
    }
    // Fill the allocated memory st
    constructSTUtil(inputArray, 0, n-1, st, 0);
/*
    for (LL i = 0; i < max_size; ++i) {
    	cout<<"Array index "<<i<<" : max Sum = "<<st[i].maxSum<<" max num = "<<st[i].maxNum<<endl;
    } */
 
    // Return the constructed segment tree
    return st;
}

int main() {
	LL N;
	scan(&N);
	LL arr[N];
	for (LL i = 0; i < N; ++i) {
		scan(&arr[i]);
	}
	Node *st = constructST(arr, N);
	LL Q;
	scan(&Q);
	for (int i = 0; i < Q; ++i) {
		LL x, y;
		char option;
		scanf("%c", &option);			
		scan(&x); scan(&y);
		if (option == 'Q') {
		    print(getMax(st, N, x-1, y-1).maxSum);
		    putchar('\n');
		} else {
			updateValue(st, N, x-1, y);
		}
	}
}