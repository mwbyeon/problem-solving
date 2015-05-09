#include <iostream>
using namespace std;

int main()
{
	int T, n;
	int card[13];
	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d", &n);
		memset(card, 0, sizeof(card));

		int k = 0;
		for ( int i=0 ; i<n ; ++i ) {
			for ( int j=0 ; j<=i ; ) {
				if ( card[k++]==0 ) ++j;
				k %= n;
			}
			while ( card[k] ) {
				++k;
				k %= n;
			}
			card[k] = i+1;
		}
		for ( int i=0 ; i<n ; ++i ) printf("%d ", card[i]);
		puts("");
	}
	return 0;
}
