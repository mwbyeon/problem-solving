

#include <stdio.h>

void main()
{
     int deci,duo,hexa;
     int i,j;
     int num;

     for ( i=2992 ; i<10000 ; i++)
     {
          deci=duo=hexa=0;

          num = i;
          for ( j=0 ; j<4 ; j++) {
               deci += num%10;
               num /= 10;
          }
          //printf("deci : %d\n",deci);
          
          num = i;
          for ( j=0 ; j<4 ; j++)
          {
               duo += num%12 ;
               num /= 12 ;
          }
          //printf("duo : %d\n",duo);

          num = i;          
          for ( j=0 ; j<4 ; j++)
          {
               hexa += num%16 ;
               num /= 16 ;
          }
          //printf("hexa : %d\n",hexa);

          if ( deci == duo && duo == hexa)
               printf("%d\n",i);
     }
}