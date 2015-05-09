
#include <cstdio>
#include <iostream>
using namespace std;

int tudoku[10][10];
int row[10], col[10], cell[3][3], empty_cnt;

void init()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(cell, 0, sizeof(cell));
	empty_cnt=0;
}

void input_tudoku()
{
	for ( int i=0 ; i<9 ; ++i ) {
		for ( int j=0 ; j<9 ; ++j ) {
			scanf("%1d", &tudoku[i][j]);
			if ( tudoku[i][j]==0 ) {
				empty_cnt++;
				row[i]++;
				col[j]++;
				cell[i/3][j/3]++;
			}
		}
	}
}

void print_tudoku()
{
	for ( int i=0 ; i<9 ; ++i ) {
		for ( int j=0 ; j<9 ; ++j )
			printf("%d", tudoku[i][j]);
		puts("");
	}
	puts("");
}

void fill_row(int n) 
{
	int fill=45, empty=-1;
	for ( int i=0 ; i<9 ; ++i ) {
		if ( tudoku[n][i]==0 ) {
			empty = i;
		}
		fill -= tudoku[n][i];
	}
	tudoku[n][empty] = fill;
	row[n]--;
	col[empty]--;
	cell[n/3][empty/3]--;
}

void fill_col(int n)
{
	int fill=45, empty=-1;
	for ( int i=0 ; i<9 ; ++i ) {
		if ( tudoku[i][n]==0 ) {
			empty = i;
		}
		fill -= tudoku[i][n];
	}
	tudoku[empty][n] = fill;
	row[empty]--;
	col[n]--;
	cell[empty/3][n/3]--;
}

void fill_cell(int n, int m)
{
	int fill=45, *empty=NULL, r, c;
	n = n*3;
	m = m*3;
	for ( int i=0 ; i<3 ; ++i ) {
		for ( int j=0 ; j<3 ; ++j ) {
			
			if ( tudoku[n+i][m+j]==0 ) {
				r = n+i;
				c = m+j;
				empty = &tudoku[r][c];
			}
			fill -= tudoku[n+i][m+j];
		}
	}
	*empty = fill;
	row[r]--;
	col[c]--;
	cell[n/3][m/3]--;
}


void process_tudoku()
{
	int i, j;

	while ( empty_cnt>0 ) {
		for ( i=0 ; i<9 ; ++i ) {
			if ( row[i]==1 ) {
				fill_row(i);
				empty_cnt--;
			}
		}
		for ( i=0 ; i<9 ; ++i ) {
			if ( col[i]==1 ) {
				fill_col(i);
				empty_cnt--;
			}
		}
		for ( i=0 ; i<3 ; ++i ) {
			for ( j=0 ; j<3 ; ++j ) {
				if ( cell[i][j]==1 ) {
					fill_cell(i,j);
					empty_cnt--;
				}
			}
		}
	}
}

int main()
{
	int T, t;
	for ( scanf("%d\n",&T), t=0 ; t<T ; ++t ) 
	{
		init();
		input_tudoku();
		process_tudoku();
		printf("Scenario #%d:\n", t+1);
		print_tudoku();		
	}
	return 0;
}
