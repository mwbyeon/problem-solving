
#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, res=0, r;
	scanf("%d", &n);
	for ( i=1 ; (r=(i*i-i)/2)<n ; ++i )
		if ( !((n-r)%i) ) ++res;
	printf("%d\n", res);
	return 0;
}
