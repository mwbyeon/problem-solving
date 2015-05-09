
#include <stdio.h>

void main()
{
    int i,n,x,y,out[100]={0};
    
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d %d",&x,&y);
        if(x<y)
            out[i]=1;
    }

    for(i=0 ; i<n ; i++)
        if(out[i])
            printf("NO BRAINS\n");
        else
            printf("MMM BRAINS\n");
}