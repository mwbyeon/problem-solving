
#include <stdio.h>
#include <math.h>

typedef unsigned long TYPE;

int bc(TYPE n, TYPE k)
{
	if ( n==k || k==0 ) return 1;
	return (bc(n-1,k-1)+bc(n-1,k))&1;
}

int sierpinski(TYPE n, TYPE k)
{
	TYPE t;
	if ( n==k || k==0 ) return 1;

	t=1;
	while ( t<=n ) 
		t <<= 1;

	while ( t>4 ) {
		t >>= 1;
		if ( k>=t ) {
			k -= t;
			n -= t;
		}
		else if ( n<t ) {
		}
		else if ( n-t>=k ) {
			n -= t;
		}
		else return 0;
//		printf("%lu (%lu, %u)\n",t, n, k);
	}
	if ( n==2 && k==1 ) 
		return 0;
	else 
		return 1;
}

int main()
{
	TYPE n, k;
//	printf("%ld\n", (long)pow(2,31));

	while ( scanf("%lu %lu", &n, &k)!=EOF ) {
//		printf("%d ", bc(n, k));
		if ( sierpinski(n, k) ) 
			puts("1");
		else
			puts("0");
	}
	return 0;
}
