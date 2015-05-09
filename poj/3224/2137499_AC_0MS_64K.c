
#include <stdio.h>

int main()
{
	int n, i, j;
	int w, wins;
	int max_match=0, max_num=0;

	scanf("%d", &n);

	for ( i=0 ; i<n ; ++i ) {
		wins = 0;
		for ( j=0 ; j<n ; ++j ) {
			scanf("%d", &w);
			if ( w==3 ) wins++;
		}
		if ( wins > max_match ) {
			max_match = wins;
			max_num = i+1;
		}
	}
	printf("%d\n", max_num);
	return 0;
}
