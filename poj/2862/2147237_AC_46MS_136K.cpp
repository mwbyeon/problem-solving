
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	bool post[10024], all_broken, perfect;
	int wooden;
	int n, i, s;

	while ( cin >> n, n ) {
		all_broken = true;
		perfect = true;
		for ( i=0 ; i<n ; ++i ) {
			cin >> post[i];
			post[i+n] = post[i];
			all_broken &= !post[i];
			perfect &= post[i];
		}
		if ( all_broken ) {
			cout << (n+1)/2 << endl;
		}
		else if ( perfect ) {
			cout << 0 << endl;
		}
		else {
			wooden = 0;
			for ( s=0 ; !post[s] ; s++ );
			for ( i=s ; i<s+n ; ++i ) {
				while ( i<s+n && post[i] )++i;
				if ( !post[i] && !post[i+1] ) {
					post[i+1] = 1;
					wooden++;
				}
			}
			cout << wooden << endl;
		}
	}
	return 0;
}
