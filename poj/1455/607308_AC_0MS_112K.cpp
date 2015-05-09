
#include <iostream>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while ( t-- )
	{
		cin >> n;
		cout << (n/2)*((n-1)/2) << endl;
	}
}