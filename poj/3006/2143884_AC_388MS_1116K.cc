
#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;

#define MAX 1000001

int main()
{
	bool prime[MAX];
	int i, j;
	int a, d, n;
	
	memset(prime, 0x01, sizeof(prime));

	// set prime;
	prime[0] = prime[1] = false;
	for ( i=4 ; i<MAX ; i+=2 ) 
		prime[i] = false;
	for ( i=3 ; i<MAX ; i+=2 )
		if ( prime[i] ) 
			for ( j=i+i ; j<MAX ; j+=i )
				prime[j] = false;

	while ( scanf("%d %d %d", &a, &d, &n), a && d && n ) {
		for ( i=0 ; i<n ; ++i ) {
			while ( !prime[a] ) a += d;
			a += d;
		}
		printf("%d\n", a-d);
	}
	return 0;
}
