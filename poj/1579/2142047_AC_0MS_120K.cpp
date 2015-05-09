
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 21

int main()
{
	int w[MAX][MAX][MAX];
	int i, j, k;

	for ( i=0 ; i<MAX ; ++i ) {
		for ( j=0 ; j<=i ; ++j ){
			w[0][i][j] = w[0][j][i] = 1;
			w[i][0][j] = w[j][0][i] = 1;
			w[i][j][0] = w[j][i][0] = 1;
		}
	}

	for ( i=1 ; i<MAX ; ++i ) {
		for ( j=1 ; j<MAX ; ++j ) {
			for ( k=1 ; k<MAX ; ++k ) {
				if ( i<j && j<k )
					w[i][j][k] = w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
			}
		}
	}

	while ( scanf("%d %d %d", &i, &j, &k), i!=-1 || j!=-1 || k!=-1 ) {
		printf("w(%d, %d, %d) = ", i, j, k);
		if ( i<=0 || j<=0 || k <=0 )
			printf("1\n");
		else if ( i>20 || j>20 || k>20 )
			printf("%d\n", w[20][20][20]);
		else
			printf("%d\n", w[i][j][k]);
	}
	return 0;
}
