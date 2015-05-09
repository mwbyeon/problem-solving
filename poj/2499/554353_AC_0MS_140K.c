#include <stdio.h>

int main()
{
    int t, s=1;
    unsigned long a, b, left, right;

    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%ld %ld", &a, &b);

        left = right = 0;

        while ( !(a==1 && b==1) )
        {
            if ( a>b ) {
                if ( b==1 ) {
                    left += a-1;
                    a = 1;
                }
                else {
                    left += a/b;
                    a %= b;
                }
            }
            if ( b>a ) {
                if ( a==1 ) {
                    right += b-1;
                    b = 1;
                }
                else {
                    right += b/a;
                    b %= a;
                }
            }
        }

        printf("Scenario #%d:\n%ld %ld\n\n",s++, left, right);
    }
    return 0;
}

