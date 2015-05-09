#include <stdio.h>

void main()
{
	int num[10];
	int result[10];
	int i,j,cnt;
	
	for (i=0 ; i<10 ; i++) {
		num[i] = 0;
		result[i]=0;
	}

	for ( cnt=0 ; scanf("%d",&num[cnt])!=EOF ; cnt++);

	for ( i=0 ; i<cnt ; i++)
	{
		for ( j=0 ; num[i]>9 ; j++)
		{
			result[j] += num[i]%10 ;
			num[i] /= 10 ;
		}
		result[j] += num[i];
	}

	for ( i=j ; i>=0 ; i--)
		printf("%d",result[i]%10);
}
