#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool cmp_black(string s1, string s2) {
	if ( isupper(s1[0]) != isupper(s2[0]) ) return isupper(s1[0]);
	if ( islower(s1[0]) && islower(s2[0]) ) {
		if ( s1[1] == s2[1] ) return s1[0] < s2[0];
		return s1[1] > s2[1];
	}

	int p1 = string("KQRBN").find(s1[0]);
	int p2 = string("KQRBN").find(s2[0]);
	if ( p1 == p2 ) {
		if ( s1[2] == s2[2] ) return s1[1] < s2[1];
		return s1[2] > s2[2];
	}
	return p1 < p2; 
}

bool cmp_white(string s1, string s2) {
	if ( isupper(s1[0]) != isupper(s2[0]) ) return isupper(s1[0]);
	if ( islower(s1[0]) && islower(s2[0]) ) {
		if ( s1[1] == s2[1] ) return s1[0] < s2[0];
		return s1[1] < s2[1];
	}		

	int p1 = string("KQRBN").find(s1[0]);
	int p2 = string("KQRBN").find(s2[0]);
	if ( p1 == p2 ) {
		if ( s1[2] == s2[2] ) return s1[1] < s2[1];
		return s1[2] < s2[2];
	}
	return p1 < p2; 
}

int main()
{
	char ch;
	string board;
	while ( cin >> ch ) if ( ch!='+' && ch!='-' && ch!='|' ) board += ch;
	
	vector<string> black, white;
	black.reserve(64);
	white.reserve(64);
	int len = board.length();
	for ( int i=1, n=0 ; i<len ; i+=3, ++n ) {
		if ( islower(board[i]) ) {
			string pos;
			if ( board[i]=='p' ) {
				pos = "a1";
				pos[0] += n%8;
				pos[1] += (63-n)/8;
			}
			else {
				pos = string(1,toupper(board[i])) + "a1";
				pos[1] += n%8;
				pos[2] += (63-n)/8;
			}
			black.push_back(pos);
		}
		else if ( isupper(board[i]) ) {
			string pos;
			if ( board[i]=='P' ) {
				pos = "a1";
				pos[0] += n%8;
				pos[1] += (63-n)/8;
			}
			else {
				pos = string(1,board[i]) + "a1";
				pos[1] += n%8;
				pos[2] += (63-n)/8;
			}
			white.push_back(pos);
		}
	}

	sort(black.begin(), black.end(), cmp_black);
	sort(white.begin(), white.end(), cmp_white);

	cout << "White: ";
	int n = white.size();
	for ( int i=0 ; i<n-1 ; ++i ) cout << white[i] << ",";
	cout << white.back() << endl;

	cout << "Black: ";
	n = black.size();
	for ( int i=0 ; i<n-1 ; ++i ) cout << black[i] << ",";
	cout << black.back() << endl;

	return 0;
}
