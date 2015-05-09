#include "Stdio.h"

int main()
{
int p,e,i,d,k=0,day;
do
{
scanf("%d%d%d%d",&p,&e,&i,&d);
k++;
if (p!=-1 && e!=-1 && i!=-1 && d!=-1)
{
p=p%23;e=e%28;i=i%33;
for(day=1;day<=21252;day++)
{
if ((day+d)%23==p && (day+d)%28==e && (day+d)%33==i)
{
printf("Case %d: the next triple peak occurs in %d days.\n",k,day);
break;
}
}  
}

}
while (p!=-1 && e!=-1 && i!=-1 && d!=-1);
return 0;
}