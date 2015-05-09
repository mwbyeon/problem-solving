// Accepted..

#include <stdio.h>

long sequence[500001]={0,};
char already[3020000];

int main()
{
    int num,i,max=0; 
    
    scanf("%d",&num);

    while ( num != -1 )
    {
        already[0] = '1';
        for ( i=1 ; i<=max ; i++ )
            already[i] = '\0';
        max = 0;

        if ( sequence[num] )
            printf("%ld\n",sequence[num]);
        else
        {
            for ( i=1 ; i<=num ; i++ ) 
            {
                sequence[i] = sequence[i-1]-i;

                if ( sequence[i]<0 || already[sequence[i]]  )
                    sequence[i] = sequence[i-1]+i;

                already[sequence[i]] = '1';

                if ( sequence[i] > max )    
                    max = sequence[i];
             }

            printf("%ld\n",sequence[num]);
        }
        scanf("%d",&num);
    }

    return 0;
}