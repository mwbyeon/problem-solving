#include <stdio.h>
void main()
{
int t,ip,m,i,j;
char a[8];
scanf("%d",&t);
while (t--)
{
for(i=0;i<4;i++){
ip=0;
m=128;
for (j=0;j<8;j++){
scanf(" %c",&a[j]);
ip += (a[j]-'0')*m;
m /= 2;
}
printf("%d",ip);
if(i==3)
printf("\n");
else
printf(".");
}
}
}