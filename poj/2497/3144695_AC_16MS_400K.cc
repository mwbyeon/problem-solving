#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int prob[25];
	for ( int T=1 ; T<=t ; ++T ) {
		int ctime, n;
		scanf("%d %d", &ctime, &n);
		for ( int i=0 ; i<n ; ++i ) scanf("%d", &prob[i]);

		sort(prob, prob+n);
		int k = 0, sum = 0, res = 0;
		while ( k<n && sum+prob[k]<=ctime ) {
			res += sum+prob[k];
			sum += prob[k++];
		}
		printf("Scenario #%d:\nSteve wins with %d solved problems and a score of %d.\n\n", T, k, res);
	}
	return 0;
}
