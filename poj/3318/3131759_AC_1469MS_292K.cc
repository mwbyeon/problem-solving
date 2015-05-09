
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

unsigned _seed = time(NULL);
inline unsigned fastRand() { return _seed=1664525*_seed+1013904223; }

int main()
{
	int n;
	int a[501], lhs[501], rhs[501], m[501];
	int i, j, t;

	for ( i=0 ; i<501 ; ++i ) m[i] = fastRand()%10+1;

	while ( scanf("%d", &n)!=EOF ) {
		int sz = sizeof(int)*n;
		memset(a, 0, sz);
		memset(lhs, 0, sz);
		memset(rhs, 0, sz);

		for ( i=0 ; i<n ; ++i )
			for ( j=0 ; j<n ; ++j )
				scanf("%d", &t), a[j] += t*m[i];

		for ( i=0 ; i<n ; ++i )
			for ( j=0 ; j<n ; ++j )
				scanf("%d", &t), lhs[j] += a[i]*t;

		for ( i=0 ; i<n ; ++i )
			for ( j=0 ; j<n ; ++j )
				scanf("%d", &t), rhs[j] += t*m[i];

		for ( i=0 ; i<n ; ++i )
			if ( lhs[i]!=rhs[i] ) break;

		puts(i==n?"YES":"NO");
	}
	return 0;
}



