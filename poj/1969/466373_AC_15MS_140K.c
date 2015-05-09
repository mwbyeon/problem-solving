

#include <stdio.h>

void main()
{
	long term,cnt;
	int i,j;
	int numer, denom;
	
	while ( scanf("%ld",&term) != EOF )
	{

		numer = denom = 1;
		cnt = term;
		while ( cnt )
		{			
			for ( i=1 ; cnt>0 ; i+=2 ) {
				for ( j=1 ; j<i && cnt>0 ; j++ )
					cnt--;
				if ( cnt>0 ) {
					for ( j=i ; j>=1 && cnt>0 ; j-- ) {
						cnt--;
					}
					numer = j+1;
				}
				else
					numer = j-1;
			}
		}
		cnt = term;
		while ( cnt )
		{			
			for ( i=2 ; cnt>0 ; i+=2 ) {
				for ( j=1 ; j<i && cnt>0 ; j++ )
					cnt--;
				if ( cnt>0 ) {
					for ( j=i ; j>=1 && cnt>0 ; j-- ) {
						cnt--;
					}
					denom = j+1;
				}
				else
					denom = j-1;
			}
		}
		printf("TERM %d IS %d/%d \n",term,numer,denom);
	}
}