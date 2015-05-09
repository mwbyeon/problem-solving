#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1121

int main()
{
	int primes[187] = {2,}, pc = 1;
	int memo[1122][15];
	memset(memo, 0, sizeof(memo));

	for ( int i=3 ; i<MAX ; i+=2 ) {
		bool flag = true;
		for ( int j=0 ; j<pc ; ++j ) {
			if ( i%primes[j]==0 ) {
				flag = false;
				break;
			}
		}
		if ( flag ) primes[pc++] = i;
	}

//	for ( int i=0 ; i<pc; ++i ) memo[primes[i]][1] = 1;

	memo[0][0] = 1;
	for ( int i=0 ; i<pc ; ++i ) {
		for ( int j=MAX-primes[i] ; j>=0 ; --j ) {
			for ( int k=14 ; k>=1 ; --k ) {
				memo[j+primes[i]][k] += memo[j][k-1];
			}
		}
	}

	int n, k;
	while ( scanf("%d %d", &n, &k), n ) printf("%d\n", memo[n][k]);

	return 0;
}
