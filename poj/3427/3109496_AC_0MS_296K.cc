#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, len;
	scanf("%d %d", &n, &len);

	int res = 0, l;
	for ( int i=0 ; i<n ; ++i ) {
		scanf("%d", &l);
		if ( l%len ) res >?= len-l%len;
	}
	printf("%d\n", res);
	return 0;
}
