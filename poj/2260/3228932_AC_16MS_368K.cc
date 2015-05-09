#include <iostream>
using namespace std;

int main()
{
	int n;
	int row[101], col[101];
	while ( scanf("%d", &n), n ) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));

		int t;
		for ( int i=0 ; i<n ; ++i ) for ( int j=0 ; j<n ; ++j ) {
			scanf("%d", &t);
			if ( t==1 ) row[i]++, col[j]++;
		}

		int cnt = 0, r, c;
		int rc = 0, cc = 0;
		bool corr = false;
		for ( int i=0 ; i<n ; ++i ) {
			if ( row[i]%2 ) {
				rc++;
				r = i;
			}
			if ( col[i]%2 ) {
				cc++;
				c = i;
			}
		}
		if ( rc==0 && cc==0 ) {
			puts("OK");
		}
		else if ( rc==1 && cc==1 ) {
			printf("Change bit (%d,%d)\n", r+1, c+1);
		}
		else {
			puts("Corrupt");
		}
	}

	return 0;
}

