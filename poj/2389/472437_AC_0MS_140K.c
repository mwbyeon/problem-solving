#include <stdio.h>
#include <string.h>

typedef struct {
     char digits[50];
     int intDigits[100];
} bignum;

int multiply ( bignum *a, bignum *b, bignum *res );
int atoi(char c);

int main()
{
     bignum a, b, res;
     
     scanf("%s%s",a.digits, b.digits);
     
     if ( strlen(a.digits) > strlen(b.digits) )
          multiply(&a, &b, &res);
     else
          multiply(&b, &a, &res);
     return 0;
}

int multiply ( bignum *a, bignum *b, bignum *res )
{
	int i,j;
	int carry=0,digit=0,temp;
	int digitCnt=0;


	if ( (int)strlen(a->digits) != 1 )
		for ( i=0 ; i<(int)strlen(a->digits)/2 ; i++ )
		{
			a->intDigits[i] = atoi(a->digits[(int)strlen(a->digits)-1-i]);
			a->intDigits[(int)strlen(a->digits)-1-i] = atoi(a->digits[i]);
			if ( strlen(a->digits)&1 )
				a->intDigits[(int)strlen(a->digits)/2] = atoi(a->digits[(int)strlen(a->digits)/2]);
		}
	else
		a->intDigits[0] = atoi(a->digits[0]);


	if ( (int)strlen(b->digits) != 1 )
		for ( i=0 ; i<(int)strlen(b->digits)/2 ; i++ ) {
			b->intDigits[i] = atoi(b->digits[(int)strlen(b->digits)-1-i]);
			b->intDigits[(int)strlen(b->digits)-1-i] = atoi(b->digits[i]);
			if ( strlen(b->digits)&1 )
				b->intDigits[(int)strlen(b->digits)/2] = atoi(b->digits[(int)strlen(b->digits)/2]);
		}
	else
		b->intDigits[0] = atoi(b->digits[0]);


	for ( i=0 ; i<(int)(strlen(a->digits)+strlen(b->digits)) ; i++ )
		res->intDigits[i] = 0;

	for ( i=0 ; i<(int)strlen(b->digits) ; i++ )
	{
		digitCnt = i;
		carry = 0;
		for ( j=0 ; j<(int)strlen(a->digits) ; j++ )
		{
			temp = a->intDigits[j]*b->intDigits[i]+res->intDigits[digitCnt]+carry;
			res->intDigits[digitCnt] = temp%10;
			carry = temp/10;
			digitCnt++;
		}
		res->intDigits[digitCnt] = carry;
	}

     i=digitCnt;
     while ( res->intDigits[i]==0 && i>0 ) i--;

     for ( ; i>=0 ; i--)
		printf("%d",res->intDigits[i]);
	printf("\n");
return 0;
}

int atoi(char c)
{
	return c-'0';
}
