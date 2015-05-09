
#include <stdio.h>

int main()
{
	int n, i, res=0, r, t, tn;
	scanf("%d", &t);
	while ( t-- ) {
		scanf("%d %d",&tn, &n);
		res = 0;
		for ( i=2 ; (r=(i*i-i)/2)<n ; ++i )
			if ( !((n-r)%i) ) ++res;
		printf("%d %d\n",tn, res);
	}
	return 0;
}
