#include <stdio.h>
#include <math.h>

int main()
{
	int year;
	unsigned long bits;

	int i, digit;
	double sum=0, logfac[769341], tmp;
	for ( i=2 ; i<769341 ; ++i) {
		sum += log10(i);
		logfac[i] = sum;
	}
	
	while ( scanf("%d", &year), year )
	{
		bits = 4;
		i = year-1960;
		i /= 10;
		bits <<= i;

		tmp = bits;
		tmp *= log10(2);
		for ( i=2 ; logfac[i]<tmp ; ++i);

		printf("%d\n", i-1);
	}
	return 0;
}

