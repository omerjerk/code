#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	unsigned int t;
	cin>>t;
	
	while (t--) {
	    long long size;
		scanf("%lld", &size);
		long long result = 0;
		for (long long i = 0; i < size + 1; ++i) {
			if (getchar() == '1')
				++result;
		}
		printf("%lld\n", result*(result + 1)/2);
	}
}