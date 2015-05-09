
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for ( int t=1 ; t<=n ; ++t )
	{
		string s1, s2, res;
		cin >> s1 >> s2;

		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());

		int len = max(s1.length(), s2.length());
		int carry=0;

		if ( s1.length() < s2.length() )
			s1.swap(s2);

		if ( s1.length() > s2.length() ) {
			int j = s1.length()-s2.length();
			for ( int i=0 ; i<j ; ++i )
				s2 += "0";
		}
		
		
		for ( int i=0 ; i<len ; ++i ) {
			int sum=s1[i]-'0'+s2[i]-'0'+carry;
			carry = sum/2;
			res += sum%2+'0';
		}
		if ( carry )
			res += "1";

		reverse(res.begin(), res.end());

		int z = res.find_first_of("1");
		if ( z==-1 )
			res = "0";
		else		
			res = res.substr(z, res.length()-z);

		cout << t << " " << res << endl;

	}

	return 0;
}
		
		
