#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1000002

bool prime[MAX];
int cntPrime[MAX];
int cntFermat[MAX];
int primes[MAX];
int pc = 0;

int main()
{
	prime[2] = 1;
	cntPrime[0] = 0;
	cntPrime[1] = 0;
	cntPrime[2] = 1;

	pc = 0;
	primes[pc++] = 2;
	for ( int i=3 ; i<MAX ; i+=2 ) {
		bool flag = 1;
		for ( int j=0 ; j<pc && primes[j]*primes[j]<=i ; ++j ) if ( i%primes[j]==0 ) {
			flag = 0;
			break;
		}
		prime[i] = flag;
		cntPrime[i] = cntPrime[i-1];

		if ( prime[i] ) {
			primes[pc++] = i;
			++cntPrime[i];
		}
		cntPrime[i+1] = cntPrime[i];
	}

	cntFermat[0] = 0;
	cntFermat[1] = 0;
	cntFermat[2] = cntFermat[3] = cntFermat[4] = 1;
	for ( int i=5 ; i<MAX ; i+=4 ) {
		cntFermat[i] = cntFermat[i-1];
		if ( prime[i] ) ++cntFermat[i];
		cntFermat[i+1] = cntFermat[i+2] = cntFermat[i+3] = cntFermat[i];
	}

	int lo, hi;
	while ( scanf("%d %d", &lo, &hi)!=EOF, lo!=-1 || hi!=-1 ) {
		printf("%d %d ", lo, hi);
		if ( lo<1 ) lo = 1;
		if ( hi<1 ) hi = 1;
		printf("%d %d\n", cntPrime[hi]-cntPrime[lo-1], cntFermat[hi]-cntFermat[lo-1]);
	}
	return 0;
}
