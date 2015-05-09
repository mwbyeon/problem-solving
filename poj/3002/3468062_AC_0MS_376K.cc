#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n;
		scanf("%d", &n);

		long long res = 1LL;
		int p;
		bool flag = true;
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%d", &p);
			if ( flag )	res = res*p/__gcd((int)res,p);
			if ( res > 1000000000LL ) flag = false;
		}
		if ( flag )
			printf("%d\n", res);
		else
			puts("More than a billion.");
	}
	return 0;
}
