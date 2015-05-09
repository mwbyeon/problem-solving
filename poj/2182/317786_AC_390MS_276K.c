#include<stdio.h>

int out_arr(int position,int size,int *out)
{
       int a,b;
       for(a=0,b=0;a<size;a++)
       {
               if(out[a] == 1)
               {
                       if(b==position)
                       {
                               out[a] = 0;
                               return a+1;
                       }
                       b++;
               }
       }

       printf("error\n");
       exit(1);
}


main()
{
       int a,b,c,d;
       int user,count,tmp,size;
       int* in;
       int* out;
       int* result;

       scanf("%d",&count);

       in = (int*) malloc(count*sizeof(int));
       out = (int*) malloc(count*sizeof(int));
       result = (int*) malloc(count*sizeof(int));

       for(a=0;a<count;a++)
               out[a] = 1;

       for(a=1;a<count;a++)
               scanf("%d",&in[a]);

       in[0] = 0;

       for(a=count-1;a>=0;a--)
               result[a] = out_arr(in[a],count,out);

       for(a=0;a<count;a++)
               printf("%d\n",result[a]);

}
