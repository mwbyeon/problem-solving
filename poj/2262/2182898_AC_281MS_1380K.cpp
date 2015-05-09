
#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define MAX 1000000

int main()
{
	int i, j;
	int n;
	bool isprime[MAX]={1,1,0};
	int prime[78499], pc=0;

	for ( i=4 ; i<MAX ; i+=2 )
		isprime[i] = true;
	pc = 0;
	prime[pc++] = 2;
	for ( i=3 ; i<MAX ; i+=2 ) {
		if ( !isprime[i] ) {
			prime[pc++] = i;
			for ( j=i+i ; j<MAX ; j+=i )
				isprime[j] = true;
		}
	}
	
	while ( scanf("%d", &n), n ) {
		for ( i=0 ; i<pc ; ++i ) {
			if ( !isprime[n-prime[i]] ) {
				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				break;
			}
		}
	}
	return 0;
}
