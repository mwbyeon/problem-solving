#include <stdio.h>

int main()
{
	double interest;
	double money;
	double sum;
	int year ;

	scanf("%lf%lf%d",&interest, &money, &year);

	interest /= 100;

	sum = 1;
	while ( year-- )
		sum *= (1+interest);


	printf("%lld\n",(long long)(money*sum));

	return 0;
}