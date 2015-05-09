
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max(x,y) (x)>(y)?(x):(y)

#define MAX 101

int n;
int row, col;
int cell[MAX][MAX];
int visited[MAX][MAX];
int start[MAX][2];
int depth[MAX];

void dfs(int i, int j)
{
	visited[i][j] = 1;
	depth[cell[i][j]]++;

	if ( i+1<=n && cell[i][j]==cell[i+1][j] && !visited[i+1][j] )
		dfs(i+1, j);
	if ( j+1<=n && cell[i][j]==cell[i][j+1] && !visited[i][j+1] )
		dfs(i, j+1);
	if ( i-1>0 && cell[i][j]==cell[i-1][j] && !visited[i-1][j] )
		dfs(i-1, j);
	if ( j-1>0 && cell[i][j]==cell[i][j-1] && !visited[i][j-1] )
		dfs(i, j-1);
}

int check() {
	int i;
	for ( i=1 ; i<n ; ++i ) {
		dfs(start[i][0], start[i][1]);
		if ( depth[i]!=n )
			return 0;
	}
	return 1;
}

int main()
{
	int i, j;

	while ( scanf("%d", &n), n ) {
		memset(cell, 0, sizeof(cell));
		memset(visited, 0, sizeof(visited));
		memset(start, 0, sizeof(start));
		memset(depth, 0, sizeof(depth));

		for ( i=1 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				scanf("%d %d", &row, &col);
				cell[row][col] = i;
			}
			start[i][0] = row;
			start[i][1] = col;
		}
		puts(check()?"good":"wrong");
	}
	return 0;
}
