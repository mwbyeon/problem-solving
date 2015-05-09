
#include <iostream>
using namespace std;

int main()
{
	int n;
	while ( cin >> n , n ) {
		if ( n&1 )
			cout << n-1 << endl;
		else
			cout << "No Solution!" << endl;
	}
	return 0;
}