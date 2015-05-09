#include <stdio.h>

#define MAX 1024
#define max(x,y) (x)>(y)?(x):(y)

int main()
{
	int n, i, j;
	int seq[MAX], best[MAX], maxlen=0;
	
	scanf("%d", &n);
	for ( i=0 ; i<n ; ++i )
		scanf("%d", &seq[i]);

	for ( i=0 ; i<n ; ++i ) {
		best[i] = 1;
		for ( j=0 ; j<i ; ++j )
			if ( seq[i]>seq[j] )
				best[i] = max(best[i],best[j]+1);
		if ( best[i]>maxlen )
			maxlen = best[i];
	}
	printf("%d\n", maxlen);
	return 0;
}
	
