#include <stdio.h>

int main()
{
   unsigned long in, digit6, num, squre, save[10000];
   int i=0, j, loop = 0, k;
   char buf[6];

   scanf("%ld",&in);

   digit6 = in;

   while(loop == 0)
   {
       sprintf(buf,"%6ld",digit6);
       for(k=1; k<5; k++)
           if(buf[k] == ' ')
               buf[k] = '0';

       num = (buf[1] - '0')*1000;
       num += (buf[2] - '0')*100;
       num += (buf[3] - '0')*10;
       num += buf[4] - '0';

       squre = num * num;
       digit6 = squre % 1000000;

       for(j=0; j<i; j++)
       {
           if(save[j] == digit6)
           {
               loop = 1;
               break;
           }
       }
       save[i++]= digit6;
   }
   printf("%ld %d %d\n",save[j], i-j-1, i);
   return 0;
}
