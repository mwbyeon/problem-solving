#include <stdio.h>

int check_length(int);
int check_atob(int,int);

void main()
{
    int a,b,max_length;

    while(scanf("%d %d",&a,&b)==2)
    {
        if(a<b)
            max_length=check_atob(a,b);
        else
            max_length=check_atob(b,a);
        printf("%d %d %d\n",a,b,max_length);

    }
}

int check_atob(int a,int b)
{
    int i,length,max_length=0;
    for (i=a ; i<=b ; i++)
    {
        length=check_length(i);   
        if(length>max_length)
            max_length=length;
    }
    return max_length;
}

int check_length(int n)
{
    int cnt=1;
    while(n!=1)
    {
        if (n%2)
            n=3*n+1;
        else
            n/=2;
        cnt++;
    }
    return cnt;
}
