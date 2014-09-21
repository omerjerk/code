#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <math.h>

#define LL long long

using namespace std;

class Node {
    public :
        int maxLeftSum;
        int maxRightSum;
        int maxSum;
        int totalSum;
};

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
Node getMaxSumUtil(Node *st, int ss, int se, int qs, int qe, int index) {
    // If segment of this node is a part of given range, then return the 
    // sum of the segment

    if (qs <= ss && qe >= se) {
        cout<<"Returning with index "<<index<<endl;
        return st[index];
    }
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe) {
        Node tempNode;
        tempNode.maxLeftSum = tempNode.maxRightSum = tempNode.maxSum = -200000;
        tempNode.totalSum = 0;
        cout<<"Returning tempNode at index = "<<index<<endl;
        return tempNode;
    }
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    Node left = getMaxSumUtil(st, ss, mid, qs, qe, 2*index+1);
    Node right = getMaxSumUtil(st, mid+1, se, qs, qe, 2*index+2);
    cout<<" INDEX = "<<index<<endl;
    cout<<"=====LEFT====="<<endl;
    cout<<"maxLeftSum = "<<left.maxLeftSum<<endl;
    cout<<"maxRightSum = "<<left.maxRightSum<<endl;
    cout<<"maxSum = "<<left.maxSum<<endl;
    cout<<"totalSum = "<<left.totalSum<<endl;
    cout<<"=====RIGHT====="<<endl;
    cout<<"maxLeftSum = "<<right.maxLeftSum<<endl;
    cout<<"maxRightSum = "<<right.maxRightSum<<endl;
    cout<<"maxSum = "<<right.maxSum<<endl;
    cout<<"totalSum = "<<right.totalSum<<endl;
    Node nodeToReturn;
    nodeToReturn.maxSum = max(left.maxSum, max(right.maxSum, left.maxRightSum + right.maxLeftSum));
    nodeToReturn.maxLeftSum = max(left.maxLeftSum, left.totalSum + right.maxLeftSum);
    nodeToReturn.maxRightSum = max(right.maxRightSum, left.maxRightSum + right.totalSum);
    nodeToReturn.totalSum = left.totalSum + right.totalSum;
    return nodeToReturn;
}
 
Node getMaxSum(Node *st, int n, int qs, int qe) { 
    return getMaxSumUtil(st, 0, n-1, qs, qe, 0);
}

void updateValueUtil(Node *st, LL ss, LL se, LL i, LL newVal, LL index) {
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

    if (se != ss) {
        LL mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, newVal, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, newVal, 2*index + 2);
        LL leftIndex = 2*index + 1; LL rightIndex = 2*index + 2;
        st[index].maxSum = max(st[leftIndex].maxSum, max(st[rightIndex].maxSum, st[leftIndex].maxRightSum + st[rightIndex].maxLeftSum));
        st[index].maxLeftSum = max(st[leftIndex].maxLeftSum, st[leftIndex].totalSum + st[rightIndex].maxLeftSum);
        st[index].maxRightSum = max(st[rightIndex].maxRightSum, st[leftIndex].maxRightSum + st[rightIndex].totalSum);
        st[index].totalSum = st[leftIndex].totalSum + st[rightIndex].totalSum;
    } else {
        st[index].maxSum = 
        st[index].maxLeftSum = 
        st[index].maxRightSum = 
        st[index].totalSum = 
        newVal;
    }
}

void updateValue(Node *st, LL n, LL i, LL new_val) {
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, new_val, 0);
}

Node constructSTUtil(Node arr[], int ss, int se, Node *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    Node left = constructSTUtil(arr, ss, mid, st, si*2+1);
    Node right = constructSTUtil(arr, mid+1, se, st, si*2+2);
    st[si].maxSum = max(left.maxSum, max(right.maxSum, left.maxRightSum + right.maxLeftSum));
    st[si].maxLeftSum = max(left.maxLeftSum, left.totalSum + right.maxLeftSum);
    st[si].maxRightSum = max(right.maxRightSum, left.maxRightSum + right.totalSum);
    st[si].totalSum = left.totalSum + right.totalSum;
    return st[si];
}
 
Node *constructST(int arr[], int n) {
    // Aintocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    Node *st = new Node[max_size];
    Node inputArray[n];
    for (int i = 0; i < n; ++i) {
        inputArray[i].maxSum = 
        inputArray[i].maxLeftSum = 
        inputArray[i].maxRightSum = 
        inputArray[i].totalSum = 
        arr[i];
    }
    // Fiint the allocated memory st
    constructSTUtil(inputArray, 0, n-1, st, 0);

    for (int i = 0; i < max_size; ++i) {
        cout<<"Index "<<i<<" | maxSum = "<<st[i].maxSum<<" maxLeft = "<<st[i].maxLeftSum<<" maxRight = "<<st[i].maxRightSum<<endl;
    }
 
    // Return the constructed segment tree
    return st;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    Node *st = constructST(arr, N);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int o,x,y;
        scanf("%d", &o);
        scanf("%d", &x);
        scanf("%d", &y);
        if (o == 0) {
            updateValue(st, N, x-1, y);
        } else {
            printf("%d\n", getMaxSum(st, N, x-1, y-1).maxSum);
        }
    }
    return 0;
}