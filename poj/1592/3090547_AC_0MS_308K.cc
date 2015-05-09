
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char font[26][32] = {
	".***..*...*.*****.*...*.*...*.",
	"****..*...*.****..*...*.****..",
	".****.*...*.*.....*......****.",
	"****..*...*.*...*.*...*.****..",
	"*****.*.....***...*.....*****.",
	"*****.*.....***...*.....*.....",
	".****.*.....*..**.*...*..***..",
	"*...*.*...*.*****.*...*.*...*.",
	"*****...*.....*.....*...*****.",

	"..***....*.....*..*..*...**...",
	"*...*.*..*..***...*..*..*...*.",
	"*.....*.....*.....*.....*****.",
	"*...*.**.**.*.*.*.*...*.*...*.",
	"*...*.**..*.*.*.*.*..**.*...*.",
	".***..*...*.*...*.*...*..***..",
	"****..*...*.****..*.....*.....",
	".***..*...*.*...*.*..**..****.",
	"****..*...*.****..*..*..*...*.",

	".****.*......***......*.****..",
	"*****.*.*.*...*.....*....***..",
	"*...*.*...*.*...*.*...*..***..",
	"*...*.*...*..*.*...*.*....*...",
	"*...*.*...*.*.*.*.**.**.*...*.",
	"*...*..*.*....*....*.*..*...*.",
	"*...*..*.*....*.....*.....*...",
	"*****....*....*....*....*****."		
};

inline bool valid(int r, int c) {
	return r<60 && c<60 && r>=0 && c>=0;
}

int main()
{
	char board[64][64];
	char comm[4];
	int sz, row, col;
	char str[64];

	memset(board, '.', sizeof(board));
	for ( int i=0 ; i<60 ; ++i ) board[i][60] = '\0';
	while ( scanf("%s ", comm)!=EOF ) {
		int len, r, c;

		switch ( comm[1] ) {
			case 'P':
				scanf("C%d %d %d |", &sz, &row, &col);
				--row, --col;
				gets(str);
				for ( int i=strlen(str) ; i>=0 && str[i]!='|' ; --i ) len = i-1;
				str[len] = '\0';

				if ( sz == 1 ) {
					for ( int i=0 ; i<len ; ++i ) {
						if ( str[i]!=' ' ) {
							r = row;
							c = col+i;
							if( valid(r,c) ) board[r][c] = str[i];
						}
					}
				}
				else {
					for ( int k=0 ; k<len ; ++k ) {
						int id = 0;
						if ( str[k]!=' ' ) {
							for ( int i=0 ; i<5 ; ++i ) {
								for ( int j=0 ; j<6 ; ++j ) {
									r = row+i;
									c = col+j;
									if ( valid(r,c) ) board[r][c] = font[str[k]-'A'][id];
									++id;
								}
							}
						}
						col += 6;
					}
				}
				break;

			case 'L':
				scanf("C%d %d |", &sz, &row);
				--row;
				gets(str);
				for ( int i=strlen(str) ; i>=0 && str[i]!='|' ; --i ) len = i-1;
				str[len] = '\0';

				col = 0;
				if ( sz==1 ) {
					for ( int i=0 ; i<len ; ++i ) {
						if ( str[i]!=' ' ) {
							r = row;
							c = col+i;
							if( valid(r,c) ) board[r][c] = str[i];
						}
					}
				}
				else {
					for ( int k=0 ; k<len ; ++k ) {
						int id = 0;
						if ( str[k]!=' ' ) {
							for ( int i=0 ; i<5 ; ++i ) {
								for ( int j=0 ; j<6 ; ++j ) {
									r = row+i;
									c = col+j;
									if ( valid(r,c) ) board[r][c] = font[str[k]-'A'][id];
									++id;
								}
							}
						}
						col += 6;
					}
				}
				break;

			case 'R':
				scanf("C%d %d |", &sz, &row);
				--row;
				gets(str);
				for ( int i=strlen(str) ; i>=0 && str[i]!='|' ; --i ) len = i-1;
				str[len] = '\0';

				if ( sz==1 ) {
					col = 60-len;
					for ( int i=len-1 ; i>=0 ; --i ) {
						if ( str[i]!=' ' ) {
							r = row;
							c = col+i;
							if( valid(r,c) ) board[r][c] = str[i];
						}
					}
				}
				else {
					col = 54;
					for ( int k=len-1 ; k>=0 ; --k ) {
						int id = 0;
						if ( str[k]!=' ' ) {
							for ( int i=0 ; i<5 ; ++i ) {
								for ( int j=0 ; j<6 ; ++j ) {
									r = row+i;
									c = col+j;
									if ( valid(r,c) ) board[r][c] = font[str[k]-'A'][id];
									++id;
								}
							}
						}
						col -= 6;
					}
				}
				break;
				
			case 'C':
				scanf("C%d %d |", &sz, &row);
				--row, --col;
				gets(str);

				for ( int i=strlen(str) ; i>=0 && str[i]!='|' ; --i ) len = i-1;
				str[len] = '\0';

				if ( sz==1 ) {
					col = 30-len/2;
					for ( int i=0 ; i<len ; ++i ) {
						if ( str[i]!=' ' ) {
							r = row;
							c = col+i;
							if( valid(r,c) ) board[r][c] = str[i];
						}
					}
					++col;
				}
				else {
					col = 30-len*3;
					for ( int k=0 ; k<len ; ++k ) {
						int id = 0;
						if ( str[k]!=' ' ) {
							for ( int i=0 ; i<5 ; ++i ) {
								for ( int j=0 ; j<6 ; ++j ) {
									r = row+i;
									c = col+j;
									if ( valid(r,c) ) board[r][c] = font[str[k]-'A'][id];
									++id;
								}
							}
						}
						col += 6;
					}
				}
				break;

			case 'E':
				for ( int i=0 ; i<60 ; ++i ) puts(board[i]);
				puts("");
				for ( int i=0 ; i<60 ; ++i ) putchar('-');
				puts("\n");

				memset(board, '.', sizeof(board));
				for ( int i=0 ; i<60 ; ++i ) board[i][60] = '\0';
				break;
			default: break;
		}
	}
	return 0;
}
