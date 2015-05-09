#include <iostream>
using namespace std;


int main()
{
	short tCase, x, y, size, i, j, blackCnt;
	char command[5];
	char grids[101][101];

	cin >> tCase;

	while ( tCase-- )
	{
		cin >> command >> x >> y >> size;
		blackCnt = 0;

		if ( !strcmp(command,"BLACK") ) {
			for ( i=x ; i<x+size ; i++ )
				for ( j=y ; j<y+size ; j++ )
					grids[i][j] = 'B';
		}
		else if ( !strcmp(command,"WHITE") ) {
			for ( i=x ; i<x+size ; i++ )
				for ( j=y ; j<y+size ; j++ )
					grids[i][j] = 'W';
		}
		else if ( !strcmp(command,"TEST") ) {
			for ( i=x ; i<x+size ; i++ )
				for ( j=y ; j<y+size ; j++ )
					if ( grids[i][j] == 'B' )
						blackCnt++;
			cout << blackCnt << endl;
		}
	}
	return 0;
}
