#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	int q, d, n, p, cent;
	for ( int t=1 ; t<=T ; ++t ) {
		scanf("%d", &cent);
		q = cent/25;
		cent %= 25;
		d = cent/10;
		cent %= 10;
		n = cent/5;
		cent %= 5;
		p = cent;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", t, q, d, n, p);
	}

	return 0;
}
