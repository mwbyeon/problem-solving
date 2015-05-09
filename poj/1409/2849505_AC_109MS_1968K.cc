#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define CLR(x,n) memset(x,n,sizeof(x))

map<string,set<string> > dic;
vector<string> res;
vector<string> out;
string seq;
int len;

bool cmp(string s1, string s2) {
	istringstream sin1(s1), sin2(s2);
	string w1, w2;
	do {
		sin1 >> w1;
		sin2 >> w2;
	} while ( w1==w2 );
	return w1 < w2;
}	

void solve(int k) {
	if ( k==len ) {
		string ss;
		REP(i, res.sz-1) ss += res[i] + " ";
		ss += res.back() + ".";
		out.pb(ss);
		return;
	}
	FOR(i, k+1, len+1) {
		string s = seq.substr(k, i-k);
		FORE(it, dic[s]) {
			res.pb(*it);
			solve(i);
			res.pop_back();
		}
	}
}

int main()
{
	int n;
	char button[] = "22233344455566677778889999";
	while ( cin >> n, n ) {
		dic.clear();
		res.clear();
		out.clear();

		REP(i, n) {
			string word, press;
			cin >> word;
			REP(j, word.sz) press += button[word[j]-'a'];
			dic[press].insert(word);
		}
		
		cin >> seq;
		len = seq.sz;
		solve(0);
		sort(ALL(out));
		REP(i, out.sz) cout << out[i] << endl;
		puts("--");
	}
	return 0;
}
