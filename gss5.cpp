#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <math.h>
#include <utility>

#define LL long long

using namespace std;

LL cumSum[11000];

class Node {
    public :
        LL maxLeftSum;
        LL maxRightSum;
        LL maxSum;
        LL totalSum;
};

// A utility function to get the middle index from corner indexes.
LL getMid(LL s, LL e) {  return s + (e -s)/2;  }
 
Node getMaxSumUtil(Node *st, LL ss, LL se, LL qs, LL qe, LL index) {
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe) {
        Node tempNode;
        tempNode.maxLeftSum = tempNode.maxRightSum = tempNode.maxSum = -200000;
        tempNode.totalSum = 0;
        return tempNode;
    }
 
    // If a part of this segment overlaps with the given range
    LL mid = getMid(ss, se);
    Node left = getMaxSumUtil(st, ss, mid, qs, qe, 2*index+1);
    Node right = getMaxSumUtil(st, mid+1, se, qs, qe, 2*index+2);
    Node nodeToReturn;
    nodeToReturn.maxSum = max(left.maxSum, max(right.maxSum, left.maxRightSum + right.maxLeftSum));
    nodeToReturn.maxLeftSum = max(left.maxLeftSum, left.totalSum + right.maxLeftSum);
    nodeToReturn.maxRightSum = max(right.maxRightSum, left.maxRightSum + right.totalSum);
    nodeToReturn.totalSum = left.totalSum + right.totalSum;
    return nodeToReturn;
}
 
LL getMaxSum(Node *st, LL n, LL x1, LL y1, LL x2, LL y2) {
    if (y1 < x2) {
        LL lquery = getMaxSumUtil(st, 0, n-1, x1, y1, 0).maxRightSum;
        LL middle = x2 > y1 ? cumSum[x2-1] - cumSum[y1] : 0;
        LL rquery = getMaxSumUtil(st, 0, n-1, x2, y2, 0).maxLeftSum;
        return lquery + middle + rquery;
    } else {
        LL left1 = getMaxSumUtil(st, 0, n-1, x1, x2, 0).maxRightSum;
        LL right1 = getMaxSumUtil(st, 0, n-1, x2+1, y2, 0).maxLeftSum;
        LL sum1 = max(left1, left1 + right1);

        LL right2 = getMaxSumUtil(st, 0, n-1, y1, y2, 0).maxLeftSum;
        LL left2 = getMaxSumUtil(st, 0, n-1, x1, y1-1, 0).maxRightSum;
        LL sum2 = max(right2, right2 + left2);

        LL sum3 = getMaxSumUtil(st, 0, n-1, x2, y1, 0).maxSum;

        return max(sum1, max(sum2, sum3));
    }
    
}

Node constructSTUtil(Node arr[], LL ss, LL se, Node *st, LL si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    LL mid = getMid(ss, se);
    Node left = constructSTUtil(arr, ss, mid, st, si*2+1);
    Node right = constructSTUtil(arr, mid+1, se, st, si*2+2);
    st[si].maxSum = max(left.maxSum, max(right.maxSum, left.maxRightSum + right.maxLeftSum));
    st[si].maxLeftSum = max(left.maxLeftSum, left.totalSum + right.maxLeftSum);
    st[si].maxRightSum = max(right.maxRightSum, left.maxRightSum + right.totalSum);
    st[si].totalSum = left.totalSum + right.totalSum;
    return st[si];
}
 
Node *constructST(LL arr[], LL n) {
    // ALLocate memory for segment tree
    LL x = (LL)(ceil(log2(n))); //Height of segment tree
    LL max_size = 2*(LL)pow(2, x) - 1; //Maximum size of segment tree
    Node *st = new Node[max_size];
    Node inputArray[n];
    for (LL i = 0; i < n; ++i) {
        inputArray[i].maxSum = 
        inputArray[i].maxLeftSum = 
        inputArray[i].maxRightSum = 
        inputArray[i].totalSum = 
        arr[i];
    }
    // FiLL the allocated memory st
    constructSTUtil(inputArray, 0, n-1, st, 0);
/*
    for (LL i = 0; i < max_size; ++i) {
        cout<<"Array index "<<i<<" : max Sum = "<<st[i].maxSum<<" max num = "<<st[i].maxNum<<endl;
    } */
 
    // Return the constructed segment tree
    return st;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        LL N;
        scanf("%lld", &N);
        LL arr[N];
        for (LL i = 0; i < 11000; ++i) {
            cumSum[i] = 0;
        }
        for (LL i = 0; i < N; ++i) {
            scanf("%lld", &arr[i]);
            if (i == 0) {
                cumSum[0] = arr[0]; continue;
            }
            cumSum[i] = cumSum[i-1] + arr[i];
        }
        Node *st = constructST(arr, N);
        int M;
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            LL x1,y1,x2,y2;
            scanf("%lld", &x1);
            scanf("%lld", &y1);
            scanf("%lld", &x2);
            scanf("%lld", &y2);
            printf("%lld\n", getMaxSum(st, N, x1-1, y1-1, x2-1, y2-1));
        }
    }    
}