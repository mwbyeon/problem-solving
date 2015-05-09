#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, string> PIS;
typedef vector<PIS> VPIS;

bool ishonest(VPIS& script, int answer) {
	for ( int i=0 ; i<script.size() ; ++i ) {
		if ( script[i].first <= answer && script[i].second=="too high" ) return 0;
		if ( script[i].first >= answer && script[i].second=="too low" ) return 0;
	}
	return 1;
}

int main()
{
	int n;
	string guess;
	VPIS script;

	while ( cin >> n, n ) {
		cin.ignore(1);
		getline(cin, guess);

		if ( guess=="right on" ) { // output
			cout << (ishonest(script, n)?"Stan may be honest":"Stan is dishonest") << endl;
			script.clear();
		}
		else {
			script.push_back(make_pair(n, guess));
		}
	}
	return 0;
}
