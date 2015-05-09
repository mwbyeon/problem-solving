#include <stdio.h>
#include <ctype.h>

int main()
{
	int i, j, row, col, res;
	char board[10][10], chess[100];

	while ( scanf("%s",chess) != EOF )
	{
		for ( i=1 ; i<=8 ; i++ ) {
			for ( j=1 ; j<=8 ; j++ ) {
				board[i][j] = '.';
			}
		}
		for ( i=0 ; i<10 ; i++ ) {
			board[0][i] = 0;
			board[9][i] = 0;
			board[i][0] = 0;
			board[i][9] = 0;
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
				board[row][col++] = chess[i];
		}

		for ( row=1 ; row<=8 ; row++ ) {
			for ( col=1 ; col<=8 ; col++ ) 
			{
				if ( board[row][col]=='p' ) {
					//if ( board[row+1][col]=='.' || board[row+1][col]=='*' )  board[row+1][col] = '*';
					if ( board[row+1][col-1]=='.' || board[row+1][col-1]=='*' )  board[row+1][col-1] = '*';
					if ( board[row+1][col+1]=='.' || board[row+1][col+1]=='*' )  board[row+1][col+1] = '*';
				}
				else if ( board[row][col]=='P' ) {
					//if ( board[row-1][col]=='.' || board[row-1][col]=='*' )  board[row-1][col] = '*';
					if ( board[row-1][col-1]=='.' || board[row-1][col-1]=='*' )  board[row-1][col-1] = '*';
					if ( board[row-1][col+1]=='.' || board[row-1][col+1]=='*' )  board[row-1][col+1] = '*';
				}
				else if ( board[row][col]=='r' || board[row][col]=='R' )  {
					for ( i=1 ; board[row+i][col]=='.' || board[row+i][col]=='*' ; i++ )  board[row+i][col] = '*';
					for ( i=1 ; board[row-i][col]=='.' || board[row-i][col]=='*' ; i++ )  board[row-i][col] = '*';
					for ( i=1 ; board[row][col+i]=='.' || board[row][col+i]=='*' ; i++ )  board[row][col+i] = '*';
					for ( i=1 ; board[row][col-i]=='.' || board[row][col-i]=='*' ; i++ )  board[row][col-i] = '*';
				}
				else if ( board[row][col]=='b' || board[row][col]=='B' ) {
					for ( i=1 ; board[row+i][col+i]=='.' || board[row+i][col+i]=='*' ; i++ )  board[row+i][col+i] = '*';
					for ( i=1 ; board[row+i][col-i]=='.' || board[row+i][col-i]=='*' ; i++ )  board[row+i][col-i] = '*';
					for ( i=1 ; board[row-i][col-i]=='.' || board[row-i][col-i]=='*' ; i++ )  board[row-i][col-i] = '*';
					for ( i=1 ; board[row-i][col+i]=='.' || board[row-i][col+i]=='*' ; i++ )  board[row-i][col+i] = '*';
				}
				else if ( board[row][col]=='q' || board[row][col]=='Q' ) {
					for ( i=1 ; board[row+i][col]=='.' || board[row+i][col]=='*'; i++ )  board[row+i][col] = '*';
					for ( i=1 ; board[row-i][col]=='.' || board[row-i][col]=='*'; i++ )  board[row-i][col] = '*';
					for ( i=1 ; board[row][col+i]=='.' || board[row][col+i]=='*'; i++ )  board[row][col+i] = '*';
					for ( i=1 ; board[row][col-i]=='.' || board[row][col-i]=='*'; i++ )  board[row][col-i] = '*';
					for ( i=1 ; board[row+i][col+i]=='.' || board[row+i][col+i]=='*' ; i++ )  board[row+i][col+i] = '*';
					for ( i=1 ; board[row+i][col-i]=='.' || board[row+i][col-i]=='*' ; i++ )  board[row+i][col-i] = '*';
					for ( i=1 ; board[row-i][col-i]=='.' || board[row-i][col-i]=='*' ; i++ )  board[row-i][col-i] = '*';
					for ( i=1 ; board[row-i][col+i]=='.' || board[row-i][col+i]=='*' ; i++ )  board[row-i][col+i] = '*';
				}
				else if ( board[row][col]=='n' || board[row][col]=='N' ) {
					if ( board[row+1][col+2]=='.' || board[row+1][col+2]=='*' )  board[row+1][col+2] = '*';
					if ( board[row+1][col-2]=='.' || board[row+1][col-2]=='*' )  board[row+1][col-2] = '*';
					if ( board[row+2][col+1]=='.' || board[row+2][col+1]=='*' )  board[row+2][col+1] = '*';
					if ( board[row+2][col-1]=='.' || board[row+2][col-1]=='*' )  board[row+2][col-1] = '*';
					if ( board[row-1][col+2]=='.' || board[row-1][col+2]=='*' )  board[row-1][col+2] = '*';
					if ( board[row-1][col-2]=='.' || board[row-1][col-2]=='*' )  board[row-1][col-2] = '*';
					if ( board[row-2][col+1]=='.' || board[row-2][col+1]=='*' )  board[row-2][col+1] = '*';
					if ( board[row-2][col-1]=='.' || board[row-2][col-1]=='*' )  board[row-2][col-1] = '*';

				}
				else if ( board[row][col]=='k' || board[row][col]=='K' ) {
					for ( i=-1 ; i<=1 ; i++ )
						for ( j=-1 ; j<=1 ; j++ )
							if ( board[row+i][col+j]=='.' || board[row+i][col+j]=='*' )  board[row+i][col+j] = '*';
				}
			}
		}
		res = 0;
		for ( row=1 ; row<=8 ; row++ ) {
			for ( col=1 ; col<=8 ; col++ ) {
//				printf("%c",board[row][col]);
				if ( board[row][col]=='.' )
					res++;
			}
//			printf("\n");
		}

		printf("%d\n",res);
	}
	return 0;
}

