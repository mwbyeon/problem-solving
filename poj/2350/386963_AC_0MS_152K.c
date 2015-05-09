
#include <stdio.h>

void main()
{
	int tcase,i;
	int grade[1000],aboveAver,stdNum;
	float average,sum;

	scanf("%d",&tcase);

	while ( tcase-- )
	{
		scanf("%d",&stdNum);

		sum = 0;
		for ( i=0 ; i<stdNum ; i++ ) {
			scanf("%d",&grade[i]);
			sum += grade[i];
		}

		average = (float)sum / (float)stdNum ;

		aboveAver = 0;
		for ( i=0 ; i<stdNum ; i++)
			if ( grade[i] > average )
				aboveAver++;

		printf("%.3f%c\n", ((float)aboveAver / (float)stdNum) * 100 , '%');
	}
}