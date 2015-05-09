#include <cstdio>
#include <memory>

int memo[22][22][22];

int go(int a, int b, int c) {
	if ( a<=0 || b<=0 || c<=0 ) return 1;
	if ( a>20 || b>20 || c>20 ) return go(20,20,20);

	int& res = memo[a][b][c];
	if ( res != 0x5F5F5F5F ) return res;
	if ( a<b && b<c ) return res = go(a,b,c-1)+go(a,b-1,c-1)-go(a,b-1,c);
	return res = go(a-1,b,c)+go(a-1,b-1,c)+go(a-1,b,c-1)-go(a-1,b-1,c-1);
}

int main()
{
	int a, b, c;
	memset(memo, 0x5F, sizeof(memo));
	while ( scanf("%d %d %d", &a, &b, &c), a!=-1 || b!=-1 || c!=-1 ) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, go(a,b,c));
	}
	return 0;
}
