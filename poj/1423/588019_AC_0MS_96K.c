
#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;
#define PI 3.1415926535
#define E 2.7182818284

int main()
{
	int n;
	ulong m;

	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%ld",&m);
		printf("%d\n",(int)(log10(sqrt(2*PI*m))+m*log10(m/E))+1);
	}
	return 0;
}