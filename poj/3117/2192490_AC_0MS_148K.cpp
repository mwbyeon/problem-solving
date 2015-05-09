
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, n, s, p;
	string name;

	while ( cin >> t >> n, t ) {
		s = 0;
		while ( t-- ) {
			cin >> name >> p;
			s += p;
		}
		cout << n*3-s << endl;
	}
	return 0;
}
