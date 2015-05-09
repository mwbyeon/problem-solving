#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<string> VS;
typedef struct PLAYER {
	int num, play;
	string name, role;
} PLAYER;

vector<PLAYER> gk, df, md, st, entry;
int fm1, fm2, fm3;

int get_period(string s) {
	int y1, y2;
	sscanf(s.c_str(), "%d-%d", &y1, &y2);
	return y2-y1+1;
}

void parse_player(string s) {
	PLAYER p;
	string period;
	istringstream sin(s);

	sin >> p.num >> p.name >> p.role;
	p.play = 0;
	while ( sin >> period )
		p.play += get_period(period);

	if ( p.role=="G" ) gk.push_back(p);
	if ( p.role=="D" ) df.push_back(p);
	if ( p.role=="M" ) md.push_back(p);
	if ( p.role=="S" ) st.push_back(p);
}

bool sort_player(PLAYER p1, PLAYER p2) {
	return p1.num < p2.num;
}

bool sort_captain(PLAYER p1, PLAYER p2) {
	if ( p1.play==p2.play ) return p1.num > p2.num;
	return p1.play > p2.play;
}

void output() {
	if ( gk.empty() || fm1>df.size() || fm2>md.size() || fm3>st.size() ) {
		puts("IMPOSSIBLE TO ARRANGE");
		return;
	}
	entry.push_back(gk[0]);	
	for ( int i=0 ; i<fm1 ; ++i ) entry.push_back(df[i]);
	for ( int i=0 ; i<fm2 ; ++i ) entry.push_back(md[i]);
	for ( int i=0 ; i<fm3 ; ++i ) entry.push_back(st[i]);
	PLAYER captain = *min_element(entry.begin(), entry.end(), sort_captain);

	printf("%d %s %s\n", captain.num, captain.name.c_str(), captain.role.c_str());
	for ( int i=0 ; i<entry.size() ; ++i )
		if ( entry[i].num != captain.num ) 
			printf("%d %s %s\n", entry[i].num, entry[i].name.c_str(), entry[i].role.c_str());
}

int main()
{
	string line;

	while ( getline(cin, line), line[0]!='0' ) {
		gk.clear();
		st.clear();
		df.clear();
		md.clear();
		entry.clear();

		parse_player(line);
		for ( int i=0 ; i<21 ; ++i ) {
			getline(cin, line);
			parse_player(line);
		}

		getline(cin, line);
		sscanf(line.c_str(), "%d-%d-%d", &fm1, &fm2, &fm3);

		sort(gk.begin(), gk.end(), sort_player);
		sort(df.begin(), df.end(), sort_player);
		sort(md.begin(), md.end(), sort_player);
		sort(st.begin(), st.end(), sort_player);

		output();
		puts("");
	}
	return 0;
}
