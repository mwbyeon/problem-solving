#include <stdio.h>

int main()
{
	int i, j, n, k, poly[10000];
	int digit;

	while ( scanf("%d %d",&n, &k), n>=0||k>=0 )
	{
		digit = 0;
		for ( i=n ; i>=0 ; i-- )
			scanf("%d",&poly[i]);
		
		for ( i=0 ; i<=n-k ; i++ ) {
			poly[i+k] -= poly[i];
			poly[i]=0;
		}

		for ( i=0 ; poly[i]==0 ; i++ );
		if ( i>n)
			printf("0");
		else
			for ( j=n ; j>=i ; j--)
				printf("%d ",poly[j]);
		printf("\n");
	}
	return 0;
}