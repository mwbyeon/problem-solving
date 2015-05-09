#include <stdio.h>

int main()
{
    long n, k, res, butts;

    while ( scanf("%ld %ld", &n, &k) != EOF )
    {
        res = butts = n;
        while ( butts>=k ) {
            res += butts/k;
            n = butts;
            butts /= k;
            butts += n%k;
        }
        printf("%ld\n",res);
    }
    return 0;
}
