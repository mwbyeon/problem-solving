#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define CLR(x,n) memset(x,n,sizeof(x))

map<string,int> tid;

struct Team {
	Team() {
		point = goal_gain = goal_loss = win = draw = loss = play = 0;
	}
	string name;
	int point, goal_gain, goal_loss, goal_diff;
	int win, draw, loss, play;
};

bool cmp(Team t1, Team t2) {
	if ( t1.point != t2.point ) return t1.point > t2.point;
	if ( t1.goal_diff != t2.goal_diff ) return t1.goal_diff > t2.goal_diff;
	if ( t1.goal_gain != t2.goal_gain ) return t1.goal_gain > t2.goal_gain;
	if ( t1.win != t2.win ) return t1.win > t2.win;
	return tid[t1.name] > tid[t2.name];
}

int main()
{
	int n, m;
	while ( cin >> n, n ) {
		tid.clear();
		vector<Team> teams(n);
		int name_len = 0;

		// input team names and assign id;
		REP(i, n) { 
			string tn;
			cin >> tn;
			teams[i].name = tn;
			tid[tn] = i;
			name_len >?= tn.sz;
		}

		// init board;
		int rows = 3+2*n;
		int cols = name_len+2+4*n;
		vector<string> board(rows, string(cols, ' '));

		string div1(string(cols, '-')), div2(string(cols, ' '));
		div1[0] = div1[name_len+1] = '+';
		div2[0] = div2[name_len+1] = '|';
		for ( int i=name_len+1 ; i<cols ; i+=4 ) {
			div1[i] = '+';
			div2[i] = '|';
		}
		REP(i, rows) board[i] = (i%2 ? div2 : div1);

		int pos = name_len+2;
		REP(i, n) {
			string tmp(teams[i].name.substr(0,3));
			tmp.resize(3,' ');
			board[1].replace(pos, 3, tmp);
			board[3+2*i].replace(1, teams[i].name.sz, teams[i].name);
			pos += 4;
		}
		for ( int i=3, j=name_len+3 ; i<rows && j<cols ; i+=2, j+=4 ) board[i][j] = 'X';

		// input game scores.
		cin >> m;
		REP(i, m) {
			string tn1, tn2, sc;
			char c;
			int s1, s2;
			cin >> tn1 >> c >> tn2 >> sc;
			board[3+2*tid[tn1]].replace(name_len+2+4*tid[tn2], 3, sc);
			sscanf(sc.c_str(), "%d:%d", &s1, &s2);
	
			Team& t1 = teams[tid[tn1]];
			Team& t2 = teams[tid[tn2]];
			t1.goal_gain += s1;
			t1.goal_loss += s2;
			t1.goal_diff = t1.goal_gain - t1.goal_loss;
			t2.goal_gain += s2;
			t2.goal_loss += s1;
			t2.goal_diff = t2.goal_gain - t2.goal_loss;
			t1.play++;
			t2.play++;
			if ( s1 > s2 ) {
				t1.win++;
				t1.point += 3;
				t2.loss++;
			}
			else if ( s1 < s2 ) {
				t2.win++;
				t2.point += 3;
				t1.loss++;
			}
			else {
				t1.draw++;
				t1.point++;
				t2.draw++;
				t2.point++;
			}
		}

		puts("RESULTS:");
		REP(i, rows) cout << board[i] << endl;
		puts("");

		sort(ALL(teams), cmp);
		vector<string> res(n), tmp(n);
		int max_len;

		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << i+1;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i] = string(max_len-tmp[i].sz,' ')+tmp[i]+". ";
		REP(i, n) res[i].append(teams[i].name + string(name_len-teams[i].name.sz, ' ') + " ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].play;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]+" ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].win;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]+" ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].draw;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]+" ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].loss;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]+" ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].goal_gain << ":" << teams[i].goal_loss;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]+" ");
		max_len = 0;
		REP(i, n) {
			ostringstream sout;
			sout << teams[i].point;
			tmp[i] = sout.str();
			max_len >?= tmp[i].sz;
		}
		REP(i, n) res[i].append(string(max_len-tmp[i].sz,' ')+tmp[i]);

		puts("STANDINGS:\n----------");
		REP(i, n) cout << res[i] << endl;
		puts("");
	}
	return 0;
}
