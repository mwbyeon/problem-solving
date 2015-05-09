#include <iostream>
#include <cstdio>
using namespace std;

#define min(x,y) (x)<(y)?(x):(y)

int table[1003][1003];

int main()
{
	int len1, len2, i, j;
	char s1[1003], s2[1003];

	while ( scanf("%d %s %d %s", &len1, &(s1[1]), &len2, &(s2[1]))!=EOF ) {
		//printf("%s %s\n", &s1[1], &s2[1]);
		for ( i=0 ; i<=len1 ; ++i ) table[i][0] = i;
		for ( j=0 ; j<=len2 ; ++j ) table[0][j] = j;

		for ( i=1 ; i<=len1 ; ++i ) {
			for ( j=1 ; j<=len2 ; ++j ) {
				table[i][j] = table[i-1][j-1]+(s1[i]!=s2[j]);
				table[i][j] = min(table[i][j], table[i][j-1]+1);
				table[i][j] = min(table[i][j], table[i-1][j]+1);
				//printf("%d ", table[i][j]);
			}
			//puts("");
		}
		printf("%d\n", table[len1][len2]);
	}
	return 0;
}
