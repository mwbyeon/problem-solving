#include <iostream>
#include <cstdio>
#include <memory>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int a[501], lhs[501], rhs[501], m[501];
	int i, j, t;

	srand(512);
	for ( i=0 ; i<501 ; ++i ) 
		m[i] = rand()%10+1;	

	while ( scanf("%d", &n)!=EOF ) {
		memset(lhs, 0, sizeof(int)*n);
		memset(rhs, 0, sizeof(int)*n);
		memset(a, 0, sizeof(int)*n);

		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				scanf("%d", &t);
				a[j] += t*m[i];
			}
		}
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				scanf("%d", &t);
				lhs[j] += a[i]*t;
			}
		}
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				scanf("%d", &t);
				rhs[j] += t*m[i];
			}
		}
		for ( i=0 ; i<n ; ++i )
			if ( lhs[i]!=rhs[i] ) break;

		puts(i==n?"YES":"NO");
	}
	return 0;
}

