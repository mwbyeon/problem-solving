#include <cstdio>

int main()
{
	unsigned memo[46];
	memo[1] = 2;
	memo[2] = 3;
	for ( int i=3 ; i<46 ; ++i )
		memo[i] = memo[i-2]+memo[i-1];
	
	int t, n;
	scanf("%d", &t);
	for ( int T=1 ; T<=t ; ++T ) {
		scanf("%d", &n);
		printf("Scenario #%u:\n%lld\n\n", T, memo[n]);
	}
	
	return 0;
}
