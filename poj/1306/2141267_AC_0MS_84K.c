
#include <stdio.h>
#include <memory.h>

#define MAX 101
typedef unsigned long TYPE;

int main()
{
	TYPE table[MAX][MAX];
	int i, j;
	int n, m;

	memset(table, 0x00, sizeof(table));
	for ( i=0 ; i<MAX ; ++i ) {
		table[i][0] = 1;
		table[i][i] = 1;
	}
	for ( i=1 ; i<MAX ; ++i )
		for ( j=1 ; j<i ; ++j )
			table[i][j] = table[i-1][j-1]+table[i-1][j];

	while ( scanf("%d %d", &n, &m), n && m )
		printf("%d things taken %d at a time is %lu exactly.\n", n, m, table[n][m]);
	return 0;
}
