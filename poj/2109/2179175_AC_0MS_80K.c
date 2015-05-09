
#include <stdio.h>
#include <math.h>

int main()
{
	long double n, p;
	
	while ( scanf("%llf %llf", &p, &n)!=EOF ) {
		printf("%ld\n", (long)(pow(n, 1/p)+0.5));
	}
	return 0;
}
