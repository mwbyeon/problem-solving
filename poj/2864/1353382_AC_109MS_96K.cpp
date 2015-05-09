
#include <iostream>
using namespace std;

int main()
{
	bool arr[102], ex, yes;
	int i, j, n, d;

	while ( cin >> n >> d, n && d )
	{
		memset(arr, 1, n);
		for ( i=0 ; i<d ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				cin >> ex;
				arr[j] &= ex;
			}
		}
		yes=0;
		for ( i=0 ; i<n && !yes ; ++i )
			yes = arr[i];
		cout << (yes?"yes":"no") << endl;
	}
	return 0;
}