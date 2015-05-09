#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) a>b?a:b
#define MAX 150

typedef struct {
    char digits[MAX];
    int last;
} bignum;

void initialize(bignum *a)
{
    memset(a->digits,0,MAX);
    a->last = -1;
}

void print_bignum(bignum *a)
{
    int i;
    for ( i=a->last ; i>=0 ; i-- )
        printf("%d",a->digits[i]);
    printf("\n");
}

void stringrev(bignum *a)
{
    int i;
    char tmp;
    for ( i=0 ; i<=a->last/2 ; i++ ) {
        tmp = a->digits[i];
        a->digits[i] = a->digits[a->last-i];
        a->digits[a->last-i] = tmp;
    }
}

void add(bignum *a, bignum *b, bignum *c)
{
    int i, carry=0;
    char tmp;

    initialize(c);

    c->last = max(a->last,b->last)+1;

    for ( i=0 ; i<=c->last ; i++ ) {
        tmp = a->digits[i]+b->digits[i]+carry;
        c->digits[i] = tmp%10;
        carry = tmp/10;
    }
    while ( (c->last>0)&&(c->digits[c->last]==0) )
        c->last--;
}

int main()
{
    int i;
    bignum n, res, tmp;
    initialize(&res);
    while ( 1 )
    {
        initialize(&n);
        scanf("%s",n.digits);
        if ( !strcmp(n.digits,"0") ) break;

        n.last = (int)strlen(n.digits)-1;
        stringrev(&n);
        for ( i=0 ; i<=n.last ; i++ )	n.digits[i] -='0';

        add(&n,&res,&tmp);
        res = tmp;
    }
    print_bignum(&res);
    return 0;
}

