#include <iostream>
using namespace std;

int main()
{
	int n, k, m;
	while ( scanf("%d %d %d", &n, &k, &m), n ) {
		int res = 0;
		for ( int i=1 ; i<n ; ++i ) res = (res+k)%i;
		printf("%d\n", (res+m)%n+1);
	}
	return 0;
}
