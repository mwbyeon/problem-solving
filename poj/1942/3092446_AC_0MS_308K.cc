#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	unsigned m, n;
	while ( scanf("%u %u", &m, &n), m || n ) {
		if ( m > n ) swap(m,n);
		double res = 1.0;
		unsigned t = m+n;
		while ( m ) {
			res *= (double)t--;
			res /= (double)m--;
		}
		printf("%.0lf\n", res);
	}
	return 0;
}
