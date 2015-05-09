#include <stdio.h>

void main()
{
int tCase,ip,mult,i,j;
char address[8];
scanf("%d",&tCase);
while ( tCase-- )
{
for ( i=0 ; i<4 ; i++ ) {
ip = 0;
mult = 128;
for ( j=0 ; j<8 ; j++ ) {
scanf(" %c",&address[j]);
ip += (address[j]-'0')*mult;
mult /= 2;
}
printf("%d",ip);
if ( i==3 )
printf("\n");
else
printf(".");
}
}
} 

