#include <stdio.h>
int main()
{
 int n,v,c;
 while(scanf("%d",&n)!=EOF){
  v=c=1;
  while(v) {
   v=(v*10+1)%n;
   c++;
  }
  printf("%d\n",c);
 }
}
