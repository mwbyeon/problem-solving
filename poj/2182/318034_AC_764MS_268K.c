
#include <stdio.h>
#define MAX 8000

void main()
{
          int num,i,j,n[MAX+1];
          int arr_num[MAX+1];
          int out[MAX+1];

          scanf("%d",&num);


          for(i=2 ; i<=num ; i++)
                   scanf("%d",&n[i]);
          for(i=1 ; i<=num ; i++)
                    arr_num[i]=i;


          for (i=num ; i>=2 ; i--)  {
                    out[i]=arr_num[n[i]+1];
                    for(j=n[i]+1 ; j<=num ; j++)
                              arr_num[j]=arr_num[j+1];
          }
          out[1]=arr_num[1];


          for(i=1 ; i<=num ; i++)
                    printf("%d\n",out[i]);
}
