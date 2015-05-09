#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1000010

bool isprime[MAX] = {0, 0, 1,};
int primes[78500] = {2,}, pc=1;

int main()
{
	for ( int i=3 ; i<MAX ; ++i ) {
		bool prime = true;
		for ( int j=0 ; j<pc && primes[j]*primes[j]<=i ; ++j ) { 
			if ( i%primes[j]==0 ) {
				prime = false;
				break;
			}
		}
		if ( prime ) {
			primes[pc++] = i;
			isprime[i] = 1;
		}
	}

	int n, a, b;
	while ( scanf("%d", &n), n ) {
		for ( int i=1 ; i<pc ; ++i ) {
			if ( isprime[n-primes[i]] ) {
				printf("%d = %d + %d\n", n, primes[i], n-primes[i]);
				break;
			}
		}
	}
	return 0;
}
