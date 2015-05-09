#include <stdio.h>
#include <ctype.h>

int main()
{
	int i, j, row, col, res;
	char org_board[10][10], att_board[10][10], chess[100];

	while ( scanf("%s",chess) != EOF )
	{
		for ( i=1 ; i<=8 ; i++ ) {
			for ( j=1 ; j<=8 ; j++ ) {
				org_board[i][j] = '.';
			}
		}
		for ( i=0 ; i<10 ; i++ ) {
			org_board[0][i] = 0;
			org_board[9][i] = 0;
			org_board[i][0] = 0;
			org_board[i][9] = 0;
		}

		row = col = 1;
		for ( i=0 ; chess[i]!=0 ; i++ )
		{
			if ( '1'<=chess[i] && chess[i]<='8' ) {
				for ( j='0' ; j<chess[i] ; j++, col++ );
			}
			else if ( chess[i] == '/' ) {
				row++;
				col = 1;
			}
			else
				org_board[row][col++] = chess[i];
		}

		for ( i=0 ; i<10 ; i++ )
			for ( j=0 ; j<10 ; j++ )
				att_board[i][j] = org_board[i][j];

		for ( row=1 ; row<=8 ; row++ ) {
			for ( col=1 ; col<=8 ; col++ )
			{
				if ( org_board[row][col]=='p' ) {
//					if ( org_board[row+1][col]=='.' )  att_board[row+1][col] = '*';
					if ( org_board[row+1][col-1]=='.' )  att_board[row+1][col-1] = '*';
					if ( org_board[row+1][col+1]=='.' )  att_board[row+1][col+1] = '*';
				}
				else if ( org_board[row][col]=='P' ) {
//					if ( org_board[row-1][col]=='.'  )  att_board[row-1][col] = '*';
					if ( org_board[row-1][col-1]=='.' )  att_board[row-1][col-1] = '*';
					if ( org_board[row-1][col+1]=='.' )  att_board[row-1][col+1] = '*';
				}
				else if ( org_board[row][col]=='r' || org_board[row][col]=='R' ) {
					for ( i=1 ; org_board[row+i][col]=='.' ; i++ )  att_board[row+i][col] = '*';
					for ( i=1 ; org_board[row-i][col]=='.' ; i++ )  att_board[row-i][col] = '*';
					for ( i=1 ; org_board[row][col+i]=='.' ; i++ )  att_board[row][col+i] = '*';
					for ( i=1 ; org_board[row][col-i]=='.' ; i++ )  att_board[row][col-i] = '*';
				}
				else if ( org_board[row][col]=='b' || org_board[row][col]=='B' ) {
					for ( i=1 ; org_board[row+i][col+i]=='.' ; i++ )  att_board[row+i][col+i] = '*';
					for ( i=1 ; org_board[row+i][col-i]=='.' ; i++ )  att_board[row+i][col-i] = '*';
					for ( i=1 ; org_board[row-i][col-i]=='.' ; i++ )  att_board[row-i][col-i] = '*';
					for ( i=1 ; org_board[row-i][col+i]=='.' ; i++ )  att_board[row-i][col+i] = '*';
				}
				else if ( org_board[row][col]=='q' || org_board[row][col]=='Q' ) {
					for ( i=1 ; org_board[row+i][col]=='.' ; i++ )  att_board[row+i][col] = '*';
					for ( i=1 ; org_board[row-i][col]=='.' ; i++ )  att_board[row-i][col] = '*';
					for ( i=1 ; org_board[row][col+i]=='.' ; i++ )  att_board[row][col+i] = '*';
					for ( i=1 ; org_board[row][col-i]=='.' ; i++ )  att_board[row][col-i] = '*';
					for ( i=1 ; org_board[row+i][col+i]=='.' ; i++ )  att_board[row+i][col+i] = '*';
					for ( i=1 ; org_board[row+i][col-i]=='.' ; i++ )  att_board[row+i][col-i] = '*';
					for ( i=1 ; org_board[row-i][col-i]=='.' ; i++ )  att_board[row-i][col-i] = '*';
					for ( i=1 ; org_board[row-i][col+i]=='.' ; i++ )  att_board[row-i][col+i] = '*';
				}
				else if ( org_board[row][col]=='n' || org_board[row][col]=='N' ) {
					if ( org_board[row+1][col+2]=='.' )  att_board[row+1][col+2] = '*';
					if ( org_board[row+1][col-2]=='.' )  att_board[row+1][col-2] = '*';
					if ( org_board[row+2][col+1]=='.' )  att_board[row+2][col+1] = '*';
					if ( org_board[row+2][col-1]=='.' )  att_board[row+2][col-1] = '*';
					if ( org_board[row-1][col+2]=='.' )  att_board[row-1][col+2] = '*';
					if ( org_board[row-1][col-2]=='.' )  att_board[row-1][col-2] = '*';
					if ( org_board[row-2][col+1]=='.' )  att_board[row-2][col+1] = '*';
					if ( org_board[row-2][col-1]=='.' )  att_board[row-2][col-1] = '*';
				}
				else if ( org_board[row][col]=='k' || org_board[row][col]=='K' ) {
					for ( i=-1 ; i<=1 ; i++ )
						for ( j=-1 ; j<=1 ; j++ )
							if ( org_board[row+i][col+j]=='.' )  att_board[row+i][col+j] = '*';
				}
			}
		}
		res = 0;
		for ( row=1 ; row<=8 ; row++ ) {
			for ( col=1 ; col<=8 ; col++ ) {
				//              printf("%c",att_board[row][col]);
				if ( att_board[row][col]=='.' )
					res++;
			}
			//          printf("\n");
		}

		printf("%d\n",res);
	}
	return 0;
}

