
#include <stdio.h>

void main()
{
    int i,n,height[50],sum,aver,move;
    int set=0,out[100]={0};

    scanf("%d",&n);
    while(n)
    {
        sum=aver=move=0;
        set++;
        for(i=0 ; i<n ; i++)
        {
            scanf("%d",&height[i]);
            sum+=height[i];
            aver=sum/n;
        }

        for(i=0 ; i<n ; i++)
            if(height[i]-aver>0)
                out[set]+=height[i]-aver;

        scanf("%d",&n);
    }
    for(i=1 ; i<=set ; i++)
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",i,out[i]);
}
