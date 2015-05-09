
#include <stdio.h>

int main()
{
	int aver, v;
	int dim[10][3];
	char name[10][10];
	int n, a, b, i;

	while ( scanf("%d",&n), n>0 ) {
		aver = 0;
		for ( i=0 ; i<n ; ++i ) {
			scanf("%d %d %d %s", &dim[i][0], &dim[i][1], &dim[i][2], name[i]);
			aver += dim[i][0]*dim[i][1]*dim[i][2];
		}
		aver /= n;
		for ( i=0 ; i<n ; ++i ) {
			v = dim[i][0]*dim[i][1]*dim[i][2];
			if ( aver<v )
				a = i;
			else if ( aver>v )
				b = i;
		}
		printf("%s took clay from %s.\n", name[a], name[b]);
	}
	return 0;
}
