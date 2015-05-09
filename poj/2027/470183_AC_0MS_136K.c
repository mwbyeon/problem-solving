#include <stdio.h>

void main()
{
	int i,n,x,y;
    
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
	{
		scanf("%d %d",&x,&y);
		if(x<y)
			puts("NO BRAINS");
		else
			puts("MMM BRAINS");
    }
}
