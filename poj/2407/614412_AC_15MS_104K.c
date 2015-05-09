#include <stdio.h>

long isPrime(long n);

int main()
{
	long num,i,prime[10000],primeCnt;
	double olier;

	scanf("%d",&num);

	while ( num )
	{
		if ( num==1 )
			olier = 0;
		else {
			for ( i=0 ; i<10000 ; i++ )
				prime[i] = 0;

			olier = (double)num;

			primeCnt = 0;
			for ( i=2 ; !isPrime(num) ; i++ ) {
				if ( isPrime(i) && num%i== 0) {
					while ( num%i == 0 )
						num /= i;
					prime[primeCnt++] = i;
				}
			}
			if ( num != 1)
				prime[primeCnt++] = num;

			for ( i=0 ; i<primeCnt ; i++ ) {
				olier *= (double)(prime[i]-1)/prime[i];
			}
		}
		printf("%d\n",(int)olier);

		scanf("%lld",&num);

	}
	return 0;
}

long isPrime(long n)
{
	long i;
	for ( i=2 ; i<=n/2 ; i++ )
		if ( n%i == 0 )
			return 0;
	return 1;
}
