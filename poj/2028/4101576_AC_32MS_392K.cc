#include <iostream>
using namespace std;

int main()
{
	int N, Q;
	int date[128];
	while ( scanf("%d %d", &N, &Q), N ) {
		memset(date, 0, sizeof(date));
	
		for ( int i=0 ; i<N ; ++i ) {
			int M, d;
			scanf("%d", &M);
			for ( int j=0 ; j<M ; ++j ) {
				scanf("%d", &d);
				date[d]++;
			}
		}

		int res = 0;
		int maxv = 0;
		for ( int i=0 ; i<128 ; ++i ) {
			if ( date[i] >= Q && maxv < date[i] ) {
				res = i;
				maxv = date[i];
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
