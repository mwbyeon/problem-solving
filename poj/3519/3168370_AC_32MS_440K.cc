#include <iostream>
using namespace std;

#define ONE_SIX 0.16666667f

int N, T, L, B;
char spcl[102];

float memo[101][101];

float solve(int from, int turn) {
	if ( from == N ) return 1.0;
	if ( turn <= 0 ) return 0.0;

	float& res = memo[from][turn];
	if ( res > -0.00001f ) return res;

	res = 0.0f;
	for ( int i=1 ; i<=6 ; ++i ) {
		int next = from+i;
		if ( next > N ) next = N-(next-N);

		if ( spcl[next]=='L' ) 
			res += solve(next, turn-2)*ONE_SIX;
		else if ( spcl[next]=='B' )
			res += solve(0, turn-1)*ONE_SIX;
		else 
			res += solve(next, turn-1)*ONE_SIX;
	}
	return res;
}

int main()
{
	while ( scanf("%d %d %d %d", &N, &T, &L, &B), N ) {
		for ( int i=0 ; i<=N ; ++i ) for ( int j=0 ; j<=T ; ++j ) memo[i][j] = -1.0f;

		memset(spcl, 0, sizeof(spcl));
		int l, b;
		for ( int i=0 ; i<L ; ++i ) scanf("%d", &l), spcl[l] = 'L';
		for ( int i=0 ; i<B ; ++i ) scanf("%d", &b), spcl[b] = 'B';

		printf("%f\n", solve(0, T));
	}
	return 0;
}

