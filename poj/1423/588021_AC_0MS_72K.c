
#include <stdio.h>
#include <math.h>

int main()
{
	int n, digit;
	unsigned long m;

	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%ld",&m);
		digit = (int)(log10(sqrt(2*3.1415926535*m))+m*log10(m/2.7182818284))+1;
		printf("%d\n",digit);
	}
return 0;
}