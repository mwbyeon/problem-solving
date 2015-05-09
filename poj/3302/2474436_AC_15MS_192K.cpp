#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool solve(string s1, string s2) {
	int i=0, j=0;
	if ( s1.length() < s2.length() ) return false;
	while ( i<s1.length() && j<s2.length() ) {
		if ( s1[i]==s2[j] ) ++j;
		++i;
	}
	return j==s2.length();
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string s1, s2;
		cin >> s1 >> s2;
		if ( solve(s1,s2) ) puts("YES");
		else {
			reverse(s2.begin(), s2.end());
			puts(solve(s1,s2)?"YES":"NO");
		}
	}
	return 0;
}

