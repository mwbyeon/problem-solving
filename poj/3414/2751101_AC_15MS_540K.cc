#include <iostream>
#include <memory>
#include <cstdio>
using namespace std;

enum { FILL_A=1, FILL_B, DROP_A, DROP_B, POUR_AB, POUR_BA };

int a, b, c;
int table[128][128]; // [a][b];
int trace[128][128];
int prev[128][128][2];

void route(int aa, int bb) {
	//printf("(%d,%d)\n", aa, bb);
	if ( aa==0 && bb==0 ) return;
	route(prev[aa][bb][0], prev[aa][bb][1]);
	switch( trace[aa][bb] ) {
		case FILL_A:
			puts("FILL(1)"); break;
		case FILL_B:
			puts("FILL(2)"); break;
		case DROP_A:
			puts("DROP(1)"); break;
		case DROP_B:
			puts("DROP(2)"); break;
		case POUR_AB:
			puts("POUR(1,2)"); break;
		case POUR_BA:
			puts("POUR(2,1)"); break;
		default: break;
	}
}

int main()
{
	memset(table, 0x7F, sizeof(table)); // INF
	memset(trace, 0xFF, sizeof(trace)); // -1

	cin >> a >> b >> c;

	table[0][0] = 0;
	for ( int k=0 ; k<max(a,b) ; ++k ) {
		for ( int i=0 ; i<=a ; ++i ) {
			for ( int j=0 ; j<=b ; ++j ) {
				int cnt = table[i][j]+1;
				if ( cnt < table[0][j] ) {
					table[0][j] = cnt;
					trace[0][j] = DROP_A;
					prev[0][j][0] = i;
					prev[0][j][1] = j;
				}
				if ( cnt < table[i][0] ) {
					table[i][0] = cnt;
					trace[i][0] = DROP_B;
					prev[i][0][0] = i;
					prev[i][0][1] = j;
				}
				if ( cnt < table[a][j] ) {
					table[a][j] = cnt;
					trace[a][j] = FILL_A;
					prev[a][j][0] = i;
					prev[a][j][1] = j;
				}
				if ( cnt < table[i][b] ) {
					table[i][b] = cnt;
					trace[i][b] = FILL_B;
					prev[i][b][0] = i;
					prev[i][b][1] = j;
				}
				int pour = b-j <? i;
				if ( cnt < table[i-pour][j+pour] ) {
					table[i-pour][j+pour] = cnt;
					trace[i-pour][j+pour] = POUR_AB;
					prev[i-pour][j+pour][0] = i;
					prev[i-pour][j+pour][1] = j;
				}
				pour = a-i <? j;
				if ( cnt < table[i+pour][j-pour] ) {
					table[i+pour][j-pour] = cnt;
					trace[i+pour][j-pour] = POUR_BA;
					prev[i+pour][j-pour][0] = i;
					prev[i+pour][j-pour][1] = j;
				}
			}
		}
	}
/*
	for ( int i=0 ; i<=a ; ++i ) {
		for ( int j=0 ; j<=b ; ++j ) 
			printf("%10d ", table[i][j]);
		puts("");
	}
*/
	int minv = 1<<30, aa, bb;
	for ( int i=0 ; i<=a ; ++i ) {
		if ( table[i][c] < minv ) {
			minv = table[i][c];
			aa = i;
			bb = c;
		}
	}
	for ( int i=0 ; i<=b ; ++i ) {
		if ( table[c][i] < minv ) {
			minv = table[c][i];
			aa = c;
			bb = i;
		}
	}
	if ( minv == 1<<30 ) {
		puts("impossible");
	}
	else {
		cout << minv << endl;
		route(aa,bb);
	}
	return 0;
}
