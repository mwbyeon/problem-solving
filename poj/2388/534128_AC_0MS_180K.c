#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
return *(int*)a - *(int*)b ;
}

void main()
{
int n, i, *milk;
scanf("%d",&n);
milk = (int*)malloc(sizeof(int)*n);
for ( i=0 ; i<n ; i++ ) scanf("%d",&milk[i]);
qsort((void*)milk,n,sizeof(int),cmp);
printf("%d\n",milk[n/2]);
}