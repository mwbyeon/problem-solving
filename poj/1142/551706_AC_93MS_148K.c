

#include <stdio.h>
#include <math.h>

int digit_sum(unsigned long n);
int isprime(unsigned long n);

int main()
{
    int t, pdigit, ndigit;
    unsigned long num, inum, i;

    for ( scanf("%ld",&num) ; num ; scanf("%ld",&num) )
    {
        //scanf("%ld",&num);

        while ( 1 )
        {
            inum = ++num;
            ndigit = digit_sum(inum);
            pdigit = 0;

            if ( !isprime(inum) ) 
            {
                while ( inum%2 == 0 ) {
                    pdigit += 2;
                    inum /= 2;
                }

                i = 3;
                while ( i<=sqrt(inum)+1 ) {
                    if ( inum%i == 0 ) {
                        pdigit += digit_sum(i);
                        inum /= i;
                    }
                    else
                        i += 2;
                }
                if ( inum > 1 )
                    pdigit += digit_sum(inum);
            }
            
            if ( ndigit == pdigit ) {
                printf("%ld\n",num);
                break;
            }
        }
    }
}

int isprime(unsigned long n)
{
    int i;
    for ( i=2 ; i<=sqrt(n) ; i++ )
        if ( n%i == 0 )
            return 0;
    return 1;
}

int digit_sum(unsigned long n)
{
    int res=0;

    while ( n > 0 ) {
        res += n%10;
        n /= 10;
    }
    return res;
}

