#include <stdio.h>
#include <memory.h>

int main()
{
	int T, n;
	int card[13];
	int i, j, k;

	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d", &n);
		memset(card, 0, sizeof(card));

		k = 0;
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<=i ; ) {
				if ( card[k++]==0 ) ++j;
				if ( k==n ) k = 0;
			}
			while ( card[k] ) {
				++k;
				if ( k==n ) k = 0;
			}
			card[k] = i+1;
		}
		for ( i=0 ; i<n ; ++i ) printf("%d ", card[i]);
		puts("");
	}
	return 0;
}
