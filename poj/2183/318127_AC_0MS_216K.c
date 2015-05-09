
#include <stdio.h>

void main()
{
     int i,loop_cnt=0,loop=1;
     unsigned long num,remain;
     unsigned long arr_num[10000];

     scanf("%d",&num);

     while(loop)
     {
          loop_cnt++;

          num %=100000;
          num /= 10;
          num = num * num;
          num %= 1000000;

          arr_num[loop_cnt] = num;
          
          for(i=1 ; i<loop_cnt ; i++)
               if(arr_num[i] == num) {
                    loop=0;
                    remain=loop_cnt-i;
               }
     }

     printf("%d %d %d\n",num,remain,loop_cnt);
}
