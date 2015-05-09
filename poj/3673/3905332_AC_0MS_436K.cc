#include <iostream>
using namespace std;

int main()
{
	string n1, n2;

	cin >> n1 >> n2;
	int l1 = n1.length();
	int l2 = n2.length();

	int res = 0;
	for ( int i=0 ; i<l1 ; ++i ) {
		for ( int j=0 ; j<l2 ; ++j ) {
			res += (n1[i]-'0') * (n2[j]-'0');
		}
	}

	cout << res << endl;

	return 0;
}
