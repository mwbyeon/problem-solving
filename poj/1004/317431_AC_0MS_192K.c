#include <stdio.h>

void main()
{
    int i;
    float money[13],aver=0,sum=0;


    for(i=1 ; i<=12 ; i++)
    {
        scanf("%f",&money[i]);
        sum+=money[i];
        aver=sum/i;
    }
    printf("$%.2f\n",aver);
}