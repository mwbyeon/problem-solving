#include <iostream>
#include <cmath>
using namespace std;

typedef long long int64;

int main()
{
	int64 n, k, nn, res=0;

	cin >> n >> k;

	nn = (int64)sqrt(n);
	for ( int64 i=1 ; i<=nn ; ++i )
		res += k%i;

	int64 c1, c2, r1, r2, q;

	c1 = nn+1;
	q = k/c1;
	while ( 1 ) {
		if ( q==0 ) c2 = n;
		else
			c2 = min(k/q, n);
		r1 = k-c1*q;
		r2 = k-c2*q;
		res += (r1+r2)*(c2-c1+1)/2;
		if ( c2==n ) break;

		c1 = c2+1;
		q = k/c1;
	}
	cout << res << endl;
	return 0;
}	
