#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	
	int p;
	while ( T-- ) {
		int n;
		scanf("%d", &n);
		int minv = INT_MAX, maxv = INT_MIN;
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%d", &p);
			minv <?= p;
			maxv >?= p;
		}
		printf("%d\n", (maxv-minv)*2);
	}
	return 0;
}
