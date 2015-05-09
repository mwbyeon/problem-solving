#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define MAX (1<<20)+1

int table[MAX][2];

int main()
{
	memset(table, 0, sizeof(table));
	table[1][0] = 0;
   	table[1][1] = 1;
	for ( int i=2 ; i<MAX ; ++i ) {
		if ( table[i][0]==0 ) table[i][0] = table[i][1] = 1;
		for ( int k=i+i ; k<MAX ; k+=i ) {
			if ( table[k][0] < table[i][0]+1 ) {
				table[k][0] = table[i][0]+1;
				table[k][1] = table[i][1];
			}
			else if ( table[k][0] == table[i][0]+1 ) {
				table[k][1] += table[i][1];
			}
		}
	}
	int n;
	while ( scanf("%d", &n)!=EOF ) printf("%d %d\n", table[n][0], table[n][1]);
	return 0;
}	
