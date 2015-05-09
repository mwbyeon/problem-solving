
#include <stdio.h>

int main()
{
	int n, s;
	char tri[20][20];
	int i, j, k;
	
	scanf("%d %d", &n, &s);

	for ( j=0 ; j<n ; ++j ) {
		for ( i=0 ; i<=j ; ++i ) {
			tri[j][i] = 0;
			tri[i][j] = s++;
			if ( s==10 ) s=1;
		}
	}

	for ( i=0 ; i<n ; ++i ) {
		for ( j=0 ; j<n ; ++j ) {
			if ( tri[i][j] )
				printf("%d ", tri[i][j]);
			else
				printf("  ");
		}
		puts("");
	}
	return 0;
}
