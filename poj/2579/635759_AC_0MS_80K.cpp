
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char vision[10][10], c;
	string command;
	int i, j;

	while ( cin >> command, command != "ENDOFINPUT" )
	{
		int a, b;
		cin >> a >> b;
		
		for ( i=0 ; i<a ; i++ ) {
			for ( j=0 ; j<b ; j++ ) {
				cin >> c;
				vision[i][j] = c-'0';
			}
		}

		for ( i=0 ; i<a-1 ; i++ ) {
			for ( j=0 ; j<b-1 ; j++ )
				cout << (vision[i][j]+vision[i][j+1]+vision[i+1][j]+vision[i+1][j+1])/4;
			cout << endl;
		}

		cin >> command;
	}
}
