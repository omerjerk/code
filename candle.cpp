#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdio.h>

#define LL long long

using namespace std;

inline void scan(int *a) {
	register char c=0;
	while (c < 33)
		c = getchar();
	*a = 0;
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar();
	}
}
static void print(int n) {
#define BSIZE 16
	char buf[BSIZE];
	int bn = BSIZE-1;
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
        LL value;
        LL max;
};

int main() {
	int t,a,b,min,pos,i;
    scanf("%d",&t);
    while(t--)
    {         min=10;
              scanf("%d",&a);
              for( i=1;i<10;i++)
                               {
                                scanf("%d",&b);
                                if(b<min) {min=b;pos=i;}
                                }   
              if(a<min)
              {
                       printf("1");
                       for( i=0;i<=a;i++)
                       printf("0");
              }        
               else
              { 
                       for( i=0;i<=min;i++)
                       printf("%d",pos);
              }          
               printf("\n");
             
              
    }
 //   getch();
    return 0;
}