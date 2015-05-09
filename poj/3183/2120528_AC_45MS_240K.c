#include <stdio.h>

#define MAX 50001

int main()
{
	int n, i;
	int hei[MAX], pre;

	scanf("%d", &n);

	for ( i=1 ; i<=n ; ++i )
		scanf("%d", &hei[i]);

	for ( i=1 ; i<=n ; ++i ) {
		while ( i<n && hei[i]<hei[i+1] )	// up
			++i;
		printf("%d\n", i);					// top
		while ( i<n && hei[i]>hei[i+1] )	// down
			++i;
	}
	return 0;
}