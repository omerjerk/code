#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <math.h>

#define LL long long

using namespace std;

class Pair {
  public:
    int x;
    int y;
};

bool comp (Pair p1, Pair p2) {
  if (p1.x < p2.x) return 1;
  if (p1.x == p2.x) 
    if (p1.y < p2.y) return 1;
  return 0;
}

int lis( Pair arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i].y >= arr[j].y && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}

int maxBridges(Pair pair[], int N) {
  sort(pair, pair + N, comp);
  return lis(pair, N);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int num;
    scanf("%d", &num);
    Pair pair[num];
    for (int i = 0; i < num; ++i) {
      scanf("%d", &pair[i].x);
    }
    for (int i = 0; i < num; ++i) {
      scanf("%d", &pair[i].y);
    }
    printf("%d\n", maxBridges(pair, num));
  }
}