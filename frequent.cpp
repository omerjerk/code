#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <math.h>
#include <utility>

#define LL long long

using namespace std;

class Node {
    public :
        int maxFreq;
        int maxRightFreq;
        int maxLeftFreq;
};

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
Node getMaxFreqUtil(Node *st, int ss, int se, int qs, int qe, int index, int arr[]) {
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    if (qs > mid)
        return getMaxFreqUtil(st, mid+1, se, qs, qe, (index<<1)+2, arr);
    if (qe <= mid)
        return getMaxFreqUtil(st, ss, mid, qs, qe, (index<<1)+1, arr);
    Node left = getMaxFreqUtil(st, ss, mid, qs, qe, (index<<1)+1, arr);
    Node right = getMaxFreqUtil(st, mid+1, se, qs, qe, (index<<1)+2, arr);
    Node nodeToReturn;
    if (arr[mid] == arr[mid+1]) {
        nodeToReturn.maxLeftFreq = left.maxLeftFreq + right.maxLeftFreq * (arr[ss] == arr[mid]);
        nodeToReturn.maxRightFreq = right.maxRightFreq + left.maxRightFreq * (arr[se] == arr[mid]);
        int temp = left.maxRightFreq + right.maxLeftFreq;
        nodeToReturn.maxFreq = max(temp, max(left.maxFreq, right.maxFreq));
    } else {
        nodeToReturn.maxLeftFreq = left.maxLeftFreq;
        nodeToReturn.maxRightFreq = right.maxRightFreq;
        nodeToReturn.maxFreq = max(left.maxFreq, right.maxFreq);
    }
    return nodeToReturn;
}
 
int getMaxFreq(Node *st, int n, int qs, int qe, int arr[]) {
    return getMaxFreqUtil(st, 0, n-1, qs, qe, 0, arr).maxFreq;
}

Node constructSTUtil(int arr[], int ss, int se, Node *st, int si) {
    if (ss == se) {
        st[si].maxLeftFreq = st[si].maxRightFreq = st[si].maxFreq = 1;
        return st[si];
    }
 
    int mid = getMid(ss, se);
    Node left = constructSTUtil(arr, ss, mid, st, (si<<1)+1);
    Node right = constructSTUtil(arr, mid+1, se, st, (si<<1)+2);
    if (arr[mid] == arr[mid+1]) {
        st[si].maxLeftFreq = left.maxLeftFreq + (right.maxLeftFreq * (arr[ss] == arr[mid]));
        st[si].maxRightFreq = right.maxRightFreq + (left.maxRightFreq * (arr[se] == arr[mid+1]));
        int temp = left.maxRightFreq + right.maxLeftFreq;
        st[si].maxFreq = max(temp, max(left.maxFreq, right.maxFreq));
    } else {
        st[si].maxLeftFreq = left.maxLeftFreq;
        st[si].maxRightFreq = right.maxRightFreq;
        st[si].maxFreq = max(left.maxFreq, right.maxFreq);
    }
    return st[si];
}
 
Node *constructST(int arr[], int n) {
    // ALLocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    Node *st = new Node[max_size];
    // Fiill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

/*
    for (int i = 0; i < max_size; ++i) {
        cout<<"Index "<<i<<" : Freq = "<<st[i].maxFreq<<" maxLeftFreq = "<<st[i].maxLeftFreq
        <<" maxRightFreq = "<<st[i].maxRightFreq<<endl;
    } */
 
    // Return the constructed segment tree
    return st;
}

int main() {
    int N;
    while(scanf("%d", &N) ==1 && N) {
        int Q;
        scanf("%d", &Q);
        int arr[N+10];
        for (int i = 0; i < N; ++i) {
            scanf("%d", &arr[i]);
        }
        Node *st = constructST(arr, N);
        for (int i = 0; i < Q; ++i) {
            int x,y;
            scanf("%d", &x); scanf("%d", &y);
            printf("%d\n", getMaxFreq(st, N, x-1, y-1, arr));
        }
    }
}