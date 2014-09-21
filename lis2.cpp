#include <iostream>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int CeilIndex(int A[], int B[], int l, int r, int keyX, int keyY) {
    int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        cout<<"New mid = "<<m<<endl;
        ((A[m] >= keyX) && (B[m] >= keyY) ? r : l) = m; // ternary expression returns an l-value
    }

    cout<<" R : "<<r<<endl;
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(int A[], int B[], int size) {
    // Add boundary case, when array size is one
 
    int *tailTableX = new int[size];
    int *tailTableY = new int[size];
    int *tempX = new int[size];
    int len; // always points empty slot
 
    memset(tailTableX, 0, sizeof(tailTableX[0])*size);
    memset(tailTableY, 0, sizeof(tailTableY[0])*size);
    memset(tempX, 0, sizeof(tempX[0])*size);
    memset(tempY, 0, sizeof(tempY[0])*size);
 
    tailTableX[0] = A[0];
    tailTableY[0] = B[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( (A[i] < tailTableX[0]) && (B[i] < tailTableY[0]) ) {
            // new smallest value
            tailTableX[0] = A[i];
            tailTableY[0] = B[i];
        } else if( (A[i] > tailTableX[len-1]) && (B[i] > tailTableY[len-1]) ) {
            // A[i] wants to extend largest subsequence
            tailTableX[len] = A[i];
            tailTableY[len] = B[i];
            ++len;
        } else {
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            int derp = CeilIndex(tailTableX, tailTableY, -1, len-1, A[i], B[i]);
            tempX[i] = tailTableX[derp];
            tempY[i] = tailTableY[derp];
            tailTableX[derp] = A[i];
            tailTableY[derp] = B[i];
        }            
    }
 
    delete[] tailTableX;
    delete[] tailTableY;
 
    return len;
}
 
int main() {
    int t;
    cin>>t;
    int X[t], Y[t];
    for (int i = 0; i < t; ++i) {
        cin>>X[i];
        cin>>Y[i];
    }
    int n = ARRAY_SIZE(X);
 
    printf("%d", LongestIncreasingSubsequenceLength(X, Y, n));
 
    return 0;
}