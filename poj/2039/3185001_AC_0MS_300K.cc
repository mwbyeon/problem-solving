#include <iostream>
using namespace std;

int main()
{
	char line[201];
	char memo[21][201];
	int n;
	while ( scanf("%d", &n), n ) {
		scanf("%s", line);
		int row=0, i=0, len=strlen(line);
		for ( int i=0 ; i<len ; ++row )
			for ( int j=0 ; j<n ; ++j, ++i ) 
				memo[row][row&1?n-j-1:j] = line[i];

		for ( int i=0 ; i<n ; ++i )
			for ( int j=0 ; j<len/n ; ++j )
				printf("%c", memo[j][i]);
		puts("");

	}
	return 0;
}

