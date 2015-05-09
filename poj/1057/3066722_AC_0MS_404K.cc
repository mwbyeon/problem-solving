#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

map< int,vector<int> > dir;
map< int,set<int> > file;
vector<string> mapping;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

void print(int idx, int indent) {
	REP(i, indent) cout << "|     ";
	cout << mapping[idx] << endl;

	FORE(it, dir[idx] ) print(*it, indent+1);
	set< pair<string,int> > files;
	FORE(it, file[idx]) files.insert(make_pair(mapping[*it], *it));
	FORE(it, files) print(it->second, indent);
}

int main()
{
	for ( int T=1 ; ; ++T ) {
		string name;
		cin >> name;
		if ( name[0]=='#' ) break;

		dir.clear();
		file.clear();
		mapping.clear();

		stack<int> st;
		st.push(0);
		mapping.push_back("ROOT");

		if ( name[0]!='*' ) {
			do {
				switch ( name[0] ) {
					case 'd':
						dir[st.top()].push_back(mapping.size());
						st.push(mapping.size());
						mapping.push_back(name);
						break;
					case 'f':
						file[st.top()].insert(mapping.size());
						mapping.push_back(name);
						break;
					case ']':
						st.pop();
						break;
				}
			} while ( cin >> name, name[0]!='*' );
		}

		cout << "DATA SET " << T << ":" << endl;
		print(0, 0);
		cout << endl;
	}
	return 0;
}
