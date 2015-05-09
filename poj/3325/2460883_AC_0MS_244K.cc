#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while ( scanf("%d", &n), n ) {
		int minv=1<<20, maxv=0, sum=0, t;
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%d", &t);
			minv <?= t;
			maxv >?= t;
			sum += t;
		}
		printf("%d\n", (sum-minv-maxv)/(n-2));
	}
	return 0;
}
