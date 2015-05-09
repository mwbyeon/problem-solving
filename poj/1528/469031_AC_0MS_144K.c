

#include <stdio.h>
#include <math.h>

void main()
{
    int num, sumFactor, i;

    scanf("%d",&num);
    printf("PERFECTION OUTPUT\n");
    
    while ( num )
    {
        printf("%5d  ",num);

        if ( num == 1 )
            sumFactor = 0;
        else
        {
            sumFactor = 1;
            for ( i=2; i<=sqrt(num) ; i++ )
                if ( num%i == 0 ) {
                    sumFactor += i + num/i;
                    if ( i == num/i )
                        sumFactor -= i;
                }
        }
        if ( sumFactor == num )
            printf("PERFECT\n");
        else if ( sumFactor > num )
            printf("ABUNDANT\n");
        else if ( sumFactor < num )
            printf("DEFICIENT\n");

        scanf("%d",&num);
    }
    printf("END OF OUTPUT\n");

}