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
        int sum;
        int minSum;
};

// A utility function to get the middle index from corner indexes.
LL getMid(LL s, LL e) {  return s + (e -s)/2;  }

void updateValue(Node *st, int ss, int se, int i, char arr[], int index) {
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

    if (se != ss) {
        int mid = getMid(ss, se);
        updateValue(st, ss, mid, i, arr, 2*index + 1);
        updateValue(st, mid+1, se, i, arr, 2*index + 2);
        int leftIndex = 2*index + 1; int rightIndex = 2*index + 2;
        st[index].sum = st[leftIndex].sum + st[rightIndex].sum;
        st[index].minSum = min(st[leftIndex].minSum, st[leftIndex].sum + st[rightIndex].minSum);
    } else {
        arr[i] = (arr[i] == '(' ? ')' : '(');
        st[index].sum = st[index].minSum = (arr[i] == '(' ? 1 : -1);
    }
}

Node constructSTUtil(char arr[], int ss, int se, Node *st, int si) {
    if (ss == se) {
        st[si].sum = st[si].minSum = (arr[ss] == '(' ? 1 : -1);
        return st[si];
    }
 
    int mid = getMid(ss, se);
    Node left = constructSTUtil(arr, ss, mid, st, (si<<1)+1);
    Node right = constructSTUtil(arr, mid+1, se, st, (si<<1)+2);
    st[si].sum = left.sum + right.sum;
    st[si].minSum = min(left.minSum, left.sum + right.minSum);
    return st[si];
}
 
Node *constructST(char arr[], int n) {
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
    int T = 10;
    while(T--) {
        cout<<"Test "<<10 - T<<":"<<endl;
        int N;
        scanf("%d", &N);
        char arr[N+10];
        cin>>arr;
        int Q;
        scanf("%d", &Q);
        Node *st = constructST(arr, N);
        for (int i = 0; i < Q; ++i) {
            int x;
            scanf("%d", &x);
            if (!x) {
                if (!st[0].sum && !st[0].minSum) {
                    printf("%s\n", "YES");
                } else {
                    printf("%s\n", "NO");
                }
            } else {
                updateValue(st, 0, N-1, x-1, arr, 0);
            }
        }
    }
}