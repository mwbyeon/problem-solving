#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

typedef vector<int> VI;

string digit("mcxi");

void parse(string s, VI& v) {
	int n=1;
	for ( int i=0 ; i<s.size() ; ++i ) {
		if ( isdigit(s[i]) ) {
			n = s[i]-'0';
		}
		else {
			v[digit.find(s[i])] = n;
			n = 1;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		VI d1(4, 0), d2(4, 0);
		string s1, s2, res;
		cin >> s1 >> s2;
		parse(s1, d1);
		parse(s2, d2);

		for ( int i=3 ; i>=0 ; --i ) {
			int sum = d1[i]+d2[i];
			if ( sum > 9 ) {
				d1[i-1]++;
				sum -= 10;
			}
			if ( sum ) {
				res = digit[i] + res;
				if ( sum>1 ) res = char(sum+'0') + res;
			}
		}
		cout << res << endl;
	}
	return 0;
}
