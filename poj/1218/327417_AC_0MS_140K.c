
#include <stdio.h>

#define MIN 5
#define MAX 100
#define LOCK   1
#define UNLOCK 0

void main()
{
     int ncase,cell;
     int jail[MAX+1],i,j,count;
     
     scanf("%d",&ncase);
     while (ncase--)
     {
          scanf("%d",&cell);

          for ( i=1 ; i<=cell ; i++ )
               if (i==1)
                    for ( j=1 ; j<=cell ; j++)
                         jail[j] = UNLOCK;
               else
                    for ( j=i ; j<=cell ; j+=i )
                         if ( jail[j] == UNLOCK )
                              jail[j] = LOCK;
                         else 
                              jail[j] = UNLOCK;
          count=0;
          for ( i=1 ; i<=cell ; i++)
               if ( jail[i]==UNLOCK ) count++;

          printf("%d\n",count);
     }
}