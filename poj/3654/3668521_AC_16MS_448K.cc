#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

map<char, set<char> > grant;

void exec(string& str)
{
	int len = str.length();
	int p = str.find_first_of("-+=");

	for ( int i=0 ; i<p ; ++i ) {
		if ( str[p] == '=' ) grant[str[i]].clear();
		for ( int j=p+1 ; j<len ; ++j ) {
			switch ( str[p] ) {
				case '-':
					grant[ str[i] ].erase(str[j]);
					break;
				case '+':
				case '=':
					grant[ str[i] ].insert(str[j]);
					break;
			}
		}
	}
}

int main()
{
	string line;
	for ( int T=1 ; cin >> line, line[0]!='#' ; ++T ) {
		grant.clear();

		int len = line.length();
		for ( int i=0 ; i<len ; ++i ) if ( line[i]==',' ) line[i] = ' ';
		istringstream sin(line);
		string str;
		while ( sin >> str ) exec(str);

		printf("%d:", T);

		vector<char> candi;
		for ( char i='A' ; i<='Z' ; ++i ) if ( !grant[i].empty() ) candi.push_back(i);

		for ( int i=0 ; i<candi.size() ; ++i ) {
			if ( !grant[candi[i]].empty() ) {
				while ( grant[candi[i]] == grant[candi[i+1]] ) {
					printf("%c", candi[i]);
					++i;
				}
				printf("%c", candi[i]);
				set<char>::iterator it = grant[candi[i]].begin();
				while ( it!=grant[candi[i]].end() ) {
					printf("%c", *it);
					++it;
				}
			}
		}
		puts("");
	}
	return 0;
}
