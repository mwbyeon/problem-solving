
#include <cstdio>
#include <memory>

#define MAX 128

int main()
{
	int tc, n, k, tmp;
	char digits[MAX+1];
	int carry, remain, dc, i;

	scanf("%d\n", &tc);
	while ( tc-- )
	{
		memset(digits, 0, sizeof(digits));
		scanf("%d %d", &n, &k);

		carry = 0;
		digits[0] = k;
		dc = 0;

		do {
			tmp = n*digits[dc]+carry;

			carry = tmp/10;
			remain = tmp%10;

			digits[++dc] = remain;
		} while ( (digits[dc-1]==0 || remain!=k || carry!=0) && dc<MAX );

		if ( dc<MAX ) {
			for ( i=dc-1 ; i>-1 ; --i )
				printf("%d",digits[i]);
			puts("");
		}
		else {
			puts("0");
		}

	}
	return 0;
}
				
			
