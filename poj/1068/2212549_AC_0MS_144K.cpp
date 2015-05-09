#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, n, i, j, k, m, cnt;
	int right, prev;
	string str;

	cin >> T;
	while ( T-- ) {
		cin >> n;
		prev = 0;
		str = "";
		for ( i=0 ; i<n ; ++i ) {
			cin >> right;
			str += string(right-prev,'(')+')';
			prev = right;
		}
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0, k=0 ; j<=i ; ++j, ++k ){
				while ( str[k]=='(' ) ++k;
			}
			for ( m=1, --k, cnt=0 ; m ; ) {
				if ( str[--k]==')' ) {
					m++;
				}
				else {
					m--;
					cnt++;
				}
			}
			cout << cnt << ' ';
		}
		cout << endl;
	}
	return 0;
}
