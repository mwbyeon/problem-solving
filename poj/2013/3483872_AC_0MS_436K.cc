#include <iostream>
using namespace std;

int main()
{
	int n;
	string str[16], s;

	for ( int t=1 ; cin >> n, n ; ++t ) {
		for ( int i=0 ; i<n ; ++i ) {
			if ( i%2==0 )
				cin >> str[i/2];
			else
				cin >> str[n-i/2-1];
		}
		cout << "SET " << t << endl;
		for ( int i=0 ; i<n ; ++i ) cout << str[i] << endl;
	}
	return 0;
}
