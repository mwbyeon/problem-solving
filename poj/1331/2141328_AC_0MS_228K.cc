
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int atoi(string num, int base)
{
	int res, digit;
	int i;
	
	reverse(num.begin(), num.end());

	res = num[0]-'0';
	digit = base;
	for ( i=1 ; i<num.length() ; ++i ) {
		res += digit*(num[i]-'0');
		digit *= base;
	}
	return res;
}

int main()
{
	string p, q, r;
	int n;
	int base, i;

	cin >> n;
	while ( n-- ) {
		cin >> p >> q >> r;

		base = 0;
		for ( i=0 ; i<p.length() ; ++i )
			base = max(p[i]-'0', base);
		for ( i=0 ; i<q.length() ; ++i )
			base = max(q[i]-'0', base);
		for ( i=0 ; i<r.length() ; ++i )
			base = max(r[i]-'0', base);

		for ( i=base+1 ; i<17 ; ++i ) {
			if ( atoi(p,i)*atoi(q,i)==atoi(r,i) ) {
				cout << i << endl;
				break;
			}
		}
		if ( i==17 ) cout << 0 << endl;
	}
	return 0;
}
