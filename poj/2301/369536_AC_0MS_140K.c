

#include <stdio.h>

int main()
{
	int tcase;
	int sum,abs,a,b;

	scanf("%d",&tcase);

	while(tcase--)
	{
		scanf("%d%d",&sum,&abs);
        

		if ( sum<abs || (abs+sum)&1)
			printf("impossible\n");
		else
		{
			a = (abs+sum) / 2 ;
			b = sum-a ;

			printf("%d %d\n",a,b);
		}			
	}
}