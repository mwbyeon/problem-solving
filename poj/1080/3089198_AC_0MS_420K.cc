
#include <iostream>
#include <cstdio>
using namespace std;

const int score[5][5] = {
	// A  C   G   T   -
	{ 5, -1, -2, -1, -3 }, // A
	{ -1, 5, -3, -2, -4 }, // C
	{ -2, -3, 5, -2, -2 }, // G
	{ -1, -2, -2, 5, -1 }, // T
	{ -3, -4, -2, -1, 0 }  // -
};

int len[2];
int gene[2][128];
int memo[128][128];

int solve(int len1, int len2) {
	int& res = memo[len1][len2];
	if ( res != INT_MIN ) return res;

	if ( len1==0 ) {
		res = 0;
		for ( int i=1 ; i<=len2 ; ++i )
			res += score[gene[1][i]][4];
		return res;
	}
	if ( len2==0 ) {
		res = 0;
		for ( int i=1 ; i<=len1 ; ++i )
			res += score[gene[0][i]][4];
		return res;
	}

	res >?= solve(len1-1, len2) + score[gene[0][len1]][4];
	res >?= solve(len1, len2-1) + score[gene[1][len2]][4];
	res >?= solve(len1-1, len2-1) + score[gene[0][len1]][gene[1][len2]];

	//printf("%d %d %d \n", len1, len2, res);

	return res;
}

int main() 
{
	int T;
	cin >> T;
	while ( T-- ) {
		cin >> len[0];
		for ( int i=1 ; i<=len[0] ; ++i ) {
			char c;
			cin >> c;
			gene[0][i] = string("ACGT").find(c);
		}
		cin >> len[1];
		for ( int i=1 ; i<=len[1] ; ++i ) {
			char c;
			cin >> c;
			gene[1][i] = string("ACGT").find(c);
		}

		for ( int i=0 ; i<=len[0] ; ++i ) 
			for ( int j=0 ; j<=len[1] ; ++j )
				memo[i][j] = INT_MIN;
		memo[0][0] = 0;

		printf("%d\n", solve(len[0], len[1]));

	}
	return 0;
}

