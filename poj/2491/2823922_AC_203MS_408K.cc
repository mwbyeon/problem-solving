#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for ( int t=1 ; t<=T ; ++t ) {
		printf("Scenario #%d:\n", t);
		int n;
		map<string,string> route;
		set<string> in, input;
		
		cin >> n;
		for ( int i=1 ; i<n ; ++i ) {
			string s1, s2;
			cin >> s1 >> s2;
			route.insert(make_pair(s1,s2));
			input.insert(s1);
			input.insert(s2);
			in.insert(s2);
		}
		string start;
		for ( set<string>::iterator it=input.begin() ; it!=input.end() ; ++it ) {
			if ( in.find(*it)==in.end() ) {
				start = *it;
				break;
			}
		}
		for ( int i=0 ; i<n ; ++i ) {
			cout << start << endl;
			start = route[start];
		}
		puts("");
	}
	return 0;
}
