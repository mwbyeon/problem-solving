#include <iostream>

#define MAX 50000

char code[MAX];
int memo[MAX];

int main()
{
	while ( gets(code), code[0]!='0' ) {
		memset(memo, 0, sizeof(memo));

		int len = strlen(code);
		for ( int i=0 ; i<len ; ++i ) code[i] -= '0';
		code[len] = 0;

		memo[0] = 1;
		for ( int i=0 ; i<len ; ++i ) {
			if ( code[i]!=0 ) memo[i+1] += memo[i];
			int t = code[i]*10+code[i+1];
			if ( i+1<len && 10<=t && t<=26 ) memo[i+2] += memo[i];
		}
		printf("%d\n", memo[len]);
	}
	return 0;
}
