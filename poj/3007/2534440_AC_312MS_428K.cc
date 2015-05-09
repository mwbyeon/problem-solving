#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string str;
		cin >> str;
		int len = str.length();

		set<string> set;
		for ( int i=1 ; i<len ; ++i ) {
			string s1 = str.substr(0, i);
			string s2 = str.substr(i);
			string tmp;

			set.insert(s1+s2);
			set.insert(s2+s1);
			tmp = s1;
			reverse(tmp.begin(), tmp.end());
			set.insert(tmp+s2);
			set.insert(s2+tmp);
			tmp = s2;
			reverse(tmp.begin(), tmp.end());
			set.insert(s1+tmp);
			set.insert(tmp+s1);
			reverse(s1.begin(), s1.end());
			set.insert(s1+tmp);
			set.insert(tmp+s1);
		}
		cout << set.size() << endl;
	}
	return 0;
}
