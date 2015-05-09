
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	string a, b;
	
	while ( cin >> a >> b, a!="0" || b!="0" ) 
	{
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		if ( a.size() < b.size() )	swap(a,b);
		for ( i=b.size() ; i<a.size() ; i++ )
			b[i] = '0';

		int carry = 0, cnt=0;
		for ( i=0 ; i<=a.size() ; ++i ) {
			if ( a[i]-'0'+b[i]-'0'+carry > 9 ) {
				cnt++;
				carry = 1;
			}
		}

		if ( cnt==0 ) 
			cout << "No carry operation." << endl;
		else if ( cnt==1 )
			cout << "1 carry operation." << endl;
		else cout << cnt << " carry operations." << endl;
	}
}