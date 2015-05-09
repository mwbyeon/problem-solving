#include <stdio.h>

#define MAX 3000

void swap (int *a,int *b)
{
     *a ^= *b ^= *a ^= *b;
}

int absolute(int a, int b)
{
     if (a>b)  return (a-b);
     else      return (b-a);
}

void main()
{
     int n,i,j;
     int array[MAX],
         abs[MAX],
         jolly;

     while ( scanf ("%d", &n) == 1 )  {
          for ( i=0 ; i<MAX ; i++)  {
               array[i]=0;
               abs[i]=0;
          }

          for ( i=0 ; i<n ; i++ )  {
               scanf("%d",&array[i]);
               if (i>0)
                    abs[i] = absolute( array[i-1], array[i] );
          }

          for ( i=1 ; i<n ; i++ )
               for ( j=i+1 ; j<n ; j++ )
                    if ( abs[i] > abs[j] )
                         swap( &abs[i], &abs[j] );
          jolly=1;
          for ( i=1 ; i<n && jolly ; i++ )
               if ( abs[i]!=i )
                    jolly=0;

          if ( jolly )  printf("Jolly\n");
          else          printf("Not jolly\n");
     }
}