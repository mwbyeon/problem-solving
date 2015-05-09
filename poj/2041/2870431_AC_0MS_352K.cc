#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()

string infer(string msg, char msgr) {
	if ( msgr=='J' ) {
		return msg[msg.sz-1] + msg.substr(0, msg.sz-1);
	}
	if ( msgr=='C' ) {
		return msg.substr(1) + msg[0];
	}
	if ( msgr=='E' ) {
		string p1(msg.substr(0, msg.sz/2));
		string p2(msg.substr((msg.sz+1)/2, msg.sz/2));
		if ( msg.sz%2 == 0 ) 
			return p2 + p1;
		else 
			return p2 + msg[msg.sz/2] + p1;
	}
	if ( msgr=='A' ) {
		reverse(msg.begin(), msg.end());
		return msg;
	}
	if ( msgr=='P' ) {
		REP(i, msg.sz) if ( isdigit(msg[i]) ) {
			if ( msg[i]=='0' ) msg[i] = '9';
			else msg[i] = msg[i]-1;
		}
		return msg;
	}
	if ( msgr=='M' ) {
		REP(i, msg.sz) if ( isdigit(msg[i]) ) {
			if ( msg[i]=='9' ) msg[i] = '0';
			else msg[i] = msg[i]+1;
		}
		return msg;
	}
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string msgr, msg;
		cin >> msgr >> msg;
		for ( int i=msgr.sz-1 ; i>=0 ; --i )
			msg = infer(msg, msgr[i]);
		cout << msg << endl;
	}
	return 0;
}
