#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int n, p[20001];
	while ( T-- ) {
		scanf("%d", &n);
		for ( int i=0 ; i<n ; ++i ) scanf("%d", &p[i]);
		sort(p, p+n, greater<int>());

		int res = 0;
		for ( int i=2 ; i<n ; i+=3 ) res += p[i];

		printf("%d\n", res);
	}
	return 0;
}
