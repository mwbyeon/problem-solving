

#include <stdio.h>

void main()
{
	int n, i;
	int seq[100001], rev[100001];

	for ( scanf("%d",&n) ; n ; scanf("%d",&n) )
	{
		for ( i=1 ; i<=n ; i++ ) {
			scanf("%d",&seq[i]);
			rev[seq[i]] = i;
		}
		for ( i=1 ; seq[i]==rev[i] && i<=n ; i++ ) ;
		if ( n == i-1 )
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
}
