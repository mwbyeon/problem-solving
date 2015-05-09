
#include <iostream>
using namespace std;

int main()
{
	int memo[1002] = {0, 3};

	for ( int i=2 ; i<1001 ; ++i ) {
		memo[i] = memo[i-1];
		for ( int j=1 ; j<i ; ++j ) if ( __gcd(i,j)==1 ) memo[i] += 2;
	}

	int T, n;
	scanf("%d", &T);
	for ( int t=1 ; t<=T ; ++t ) {
		scanf("%d", &n);
		printf("%d %d %d\n", t, n, memo[n]);
	}
	return 0;
}
