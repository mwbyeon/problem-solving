#include <iostream>
#include <cstdio>
using namespace std;

int board[1024][1024];
int orig[1024];
int rota[1024];

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int main()
{
	int n;
	for ( int T=1 ; scanf("%d", &n), n ; ++T ) {
		for ( int i=0 ; i<n ; ++i ) 
			for ( int j=0 ; j<n ; ++j ) 
				scanf("%d", &board[i][j]);

		int depth = (n+1)/2;
		int len, sz, r, c;
		int idx;
		bool yes = true;
		for ( int k=0 ; yes && k<depth ; ++k ) {
			//beg = k, end = n-k-1;
			len = n-k*2;
			if ( len == 1 ) {
				if ( board[k][k] != (n+1)*k+1 ) yes = false;
				continue;
			}

			sz = len*4-4;
			r=k, c=k;

			// rota[k][0] = (n+1)*k+1; // orig에서;
			idx = 0;
			//rota[idx++] = board[k][k];

			int go = -1;

			for ( int d=0 ; d<4 ; ++d ) {
				for ( int e=1 ; e<len ; ++e ) {
					r += dr[d];
					c += dc[d];
					rota[idx] = board[r][c];
					orig[idx] = r*n+c+1;
					if ( rota[idx]==orig[0] ) go = idx;
					++idx;
				}
			}
/*
			printf("rota : ");
			for ( int i=0 ; i<idx ; ++i ) printf("%d ", rota[i]);
			puts("");
			printf("orig : ");
			for ( int i=0 ; i<idx ; ++i ) printf("%d ", orig[i]);
			puts("");
*/

			if ( go == -1 ) {
				yes = false;
				break;
			}
			for ( int i=0 ; i<idx ; ++i, ++go ) {
				if ( go==idx ) go = 0;
				if ( rota[go]!=orig[i] ) {
					yes = false;
					break;
				}
			}
		}
		printf("%d. %s\n", T, yes?"YES":"NO");
	}
	return 0;
}
