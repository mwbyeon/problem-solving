#include <iostream>
#include <cstdio>
#include <memory>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int a[512], m[512];
	int lhs[512], rhs[512];

	while ( scanf("%d", &n)!=EOF ) {
		memset(lhs, 0, sizeof(lhs));
		memset(rhs, 0, sizeof(rhs));
		memset(a, 0, sizeof(a));

		srand(512);

		int i, j, t;
		for ( i=0 ; i<n ; ++i ) m[i] = rand()%10+1;
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				scanf("%d", &t);
				a[j] += t*m[i];
			}
		}
//		puts("matrix a");
//		for ( i=0 ; i<n ; ++i ) printf("%d ", a[i]); puts("");

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
		for ( i=0 ; i<n ; ++i ) {
//			printf("%d %d\n", lhs[i], rhs[i]);
			if ( lhs[i]!=rhs[i] ) break;
		}

		puts(i==n?"YES":"NO");
	}
	return 0;
}

