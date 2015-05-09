#include <stdio.h>
#define MAX_P  150000
#define MAX_ST 500

void main()
{
        int p,i,num[MAX_P];
        int res=0;
    
        int eat_i=1;
        int step=1;
    
        scanf("%d",&p);

        for(i=1 ; i<=p ; i++)
            scanf("%d",&num[i]);

        while(eat_i-1 != p)
        {
            if(step%2)
                    if ( num[eat_i] > num[eat_i+1] )  {
                            res += num[eat_i];
                            eat_i += 1;
                            step++;
                    }
                    else
                            eat_i++;
            else
                    if ( num[eat_i] < num[eat_i+1] )  {
                            res -= num[eat_i];
                            eat_i += 1;
                            step++;
                    }
                    else
                            eat_i++;
        }
        printf("%d\n",res);
}