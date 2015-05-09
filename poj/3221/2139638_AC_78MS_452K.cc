
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<string,int>	PSI;
typedef map<string,int> 	MSI;

MSI puzzle;

string char_swap(string s, int a, int b) {
	swap(s[a], s[b]);
	return s;
}

void bfs()
{
	string s;
	int cnt;
	queue<PSI, deque<PSI> > q;

	q.push(make_pair("0123456",0));
	while ( !q.empty() ) {
		s = q.front().first;
		cnt = q.front().second;
		q.pop();

		if ( puzzle.find(s)==puzzle.end() ) {
			puzzle[s] = cnt++;

			if ( s[0]=='0' ) {
				q.push(make_pair(char_swap(s, 0, 2), cnt));
				q.push(make_pair(char_swap(s, 0, 4), cnt));
				q.push(make_pair(char_swap(s, 0, 6), cnt));
			}
			else if ( s[1]=='0' ) {
				q.push(make_pair(char_swap(s, 1, 2), cnt));
				q.push(make_pair(char_swap(s, 1, 6), cnt));
			}
			else if ( s[2]=='0' ) {
				q.push(make_pair(char_swap(s, 2, 0), cnt));
				q.push(make_pair(char_swap(s, 2, 1), cnt));
				q.push(make_pair(char_swap(s, 2, 3), cnt));
			}
			else if ( s[3]=='0' ) {
				q.push(make_pair(char_swap(s, 3, 2), cnt));
				q.push(make_pair(char_swap(s, 3, 4), cnt));
			}
			else if ( s[4]=='0' ) {
				q.push(make_pair(char_swap(s, 4, 0), cnt));
				q.push(make_pair(char_swap(s, 4, 3), cnt));
				q.push(make_pair(char_swap(s, 4, 5), cnt));
			}
			else if ( s[5]=='0' ) {
				q.push(make_pair(char_swap(s, 5, 4), cnt));
				q.push(make_pair(char_swap(s, 5, 6), cnt));
			}
			else if ( s[6]=='0' ) {
				q.push(make_pair(char_swap(s, 6, 0), cnt));
				q.push(make_pair(char_swap(s, 6, 5), cnt));
				q.push(make_pair(char_swap(s, 6, 1), cnt));
			}
		}
	}
}
	

int main()
{
	int n;
	string s;

	bfs();

	cin >> n;
	while ( n-- ) {
		cin >> s;
		if ( puzzle.find(s)==puzzle.end() )
			cout << "-1" << endl;
		else
			cout << puzzle[s] << endl;
	}
	return 0;
}
