
#include <stdio.h>

#define YES 1
#define NO 0

int cnt_x, cnt_o,
	fill_x, fill_o;
char grid[3][3];

int check_fill()
{
	int i;
	for ( i=0 ; i<3 ; i++ ) 
	{
		// 가로줄
		if ( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] ) {
			if ( grid[i][0] == 'X' )
				fill_x++;
			else if ( grid[i][0] == 'O' )
				fill_o++;
		}
		// 세로줄
		if ( grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] ) {
			if ( grid[0][i] == 'X' )
				fill_x++;
			else if ( grid[0][i] == 'O' )
				fill_o++;
		}
	}

	// 대각선
	if ( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] ) {
		if ( grid[0][0] == 'X' )
			fill_x++;
		else if ( grid[0][0] == 'O' )
			fill_o++;
	}
	if ( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] ) {
		if ( grid[0][2] == 'X' )
			fill_x++;
		else if ( grid[0][2] == 'O' )
			fill_o++;
	}

	if ( fill_x>0 && fill_o>0 )
		return NO;

	if ( fill_x==2 ) 
		if( cnt_x==5 )
			return YES;
		else 
			return NO;

	if ( fill_x == 1 )
		if ( cnt_x==cnt_o+1 ) 
			return YES;
		else 
			return NO;

	if ( fill_o == 1 )
		if ( cnt_x==cnt_o )
			return YES;
		else
			return NO;

	if ( cnt_x==cnt_o || cnt_x==cnt_o+1 )
		return YES;

	return NO;
}

void main()
{
	int t, i, j;

	for ( scanf("%d",&t) ; t ; t-- )
	{
		cnt_x = cnt_o = fill_x = fill_o = 0;

		for ( i=0 ; i<3 ; i++ ) {
			for ( j=0 ; j<3 ; j++ ) {
				scanf(" %c",&grid[i][j]);
				if ( grid[i][j] == 'X' )
					cnt_x++;
				else if ( grid[i][j] == 'O')
					cnt_o++;
			}
		}

		if ( check_fill()==YES )
			printf("yes\n");
		else
			printf("no\n");
	}
}