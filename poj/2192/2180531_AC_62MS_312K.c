
#include <stdio.h>
#include <string.h>
#include <memory.h>

#define max(x,y) (x)>(y)?(x):(y)

#define MAX 256

int main()
{
	char str1[MAX],
		 str2[MAX],
		 str3[MAX*2];
	int T, t;
	int i, j, len1, len2, len3, m;
	int table[MAX][MAX];

	scanf("%d", &T);
	for ( t=0 ; t<T ; ++t ) {
		scanf("%s %s %s", str1, str2, str3);
		len1 = strlen(str1);
		len2 = strlen(str2);
		len3 = strlen(str3);

		memset(table, 0x00, sizeof(table));
		for ( i=0, j=0 ; i<len1 ; ++i ) {
			if ( str1[i]==str3[j] ) {
				table[i+1][0] = table[i][0]+1;
				++j;
			}
			else
				table[i+1][0] = table[i][0];
		}
		for ( i=0, j=0 ; i<len2 ; ++i ) {
			if ( str2[i]==str3[j] ) {
				table[0][i+1] = table[0][i]+1;
				++j;
			}
//			else
//				table[0][i+1] = table[0][i];
		}
		
		for ( i=1 ; i<=len1 ; ++i ) {
			for ( j=1 ; j<=len2 ; ++j ) {
/*				if ( str1[i-1]==str3[m] && str2[j-1]==str3[m] )
					table[i][j] = m+1;
				else if ( str1[i-1]==str3[table[i-1][j]] )
					table[i][j] = table[i-1][j]+1;
				else if ( str2[j-1]==str3[table[i][j-1]] )
					table[i][j] = table[i][j-1]+1;
*/
				if ( table[i][j-1] && str3[table[i][j-1]]==str2[j-1] )
					table[i][j] = table[i][j-1]+1;
				if ( table[i-1][j] && str3[table[i-1][j]]==str1[i-1] )
					table[i][j] = max(table[i][j], table[i-1][j]+1);

			}
		}
/*
		for ( i=0 ; i<=len1 ; ++i ) {
			for ( j=0 ; j<=len2 ; ++j ) {
				printf("%d ", table[i][j]);
			}
			puts("");
		}
*/
		printf("Data set %d: %s\n", t+1, table[len1][len2]==len3?"yes":"no");
	}
	return 0;
}
