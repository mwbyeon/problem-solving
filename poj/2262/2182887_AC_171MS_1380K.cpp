
#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define MAX 1000010

int main()
{
	int i, j;
	int n;
	int prime[78499], pc=0;
	bool isprime[MAX];

	memset(isprime, true, sizeof(isprime));

	isprime[2] = true;
	for ( i=4 ; i<MAX ; i+=2 )
		isprime[i] = false;
	pc = 0;
	prime[pc++] = 2;
	for ( i=3 ; i<MAX ; i+=2 ) {
		if ( isprime[i] ) {
			prime[pc++] = i;
			for ( j=i+i ; j<MAX ; j+=i )
				isprime[j] = false;
		}
	}

	while ( scanf("%d", &n), n ) {
		for ( i=0 ; i<pc ; ++i ) {
			if ( isprime[n-prime[i]] ) {
				//printf("%d ", prime[i] );
				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				break;
			}
		}
	}
	return 0;
}
