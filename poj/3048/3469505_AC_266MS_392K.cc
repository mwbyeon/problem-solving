#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int primes[2266] = {1,2,}, pc = 2;
	for ( int i=3 ; i<20000 ; i+=2 ) {
		bool flag = true;
		for ( int j=1 ; j<pc && primes[j]*primes[j]<=i ; ++j ) {
			if ( i%primes[j]==0 ) {
				flag = false;
				break;
			}
		}
		if ( flag ) primes[pc++] = i;
	}

	int T;
	scanf("%d", &T);

	int res = -1, n;
	int maxv = 0;
	while ( T-- ) {
		scanf("%d", &n);
		int* lower = lower_bound(primes, primes+pc, n);
		while ( lower >= primes ) {
			if ( *lower!=0 && n%(*lower)==0 ) {
				if ( maxv < *lower ) {
					res >?= n;
					maxv = *lower;
					break;
				}
			}
			--lower;
		}
	}
	printf("%d\n", res);
	return 0;
}
