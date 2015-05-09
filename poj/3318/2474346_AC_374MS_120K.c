#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main()
{
	int n;
	int a[501], lhs[501], rhs[501], m[501];
	int k;

	srand(16);
	for ( k=0 ; k<501 ; ++k ) 
		m[k] = rand()%10+1;	

	while ( scanf("%d", &n)!=EOF ) {
		int sz = sizeof(int)*n;
		int i, j, t;
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

