#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

inline bool issign(char c) { return (c=='-' || c=='+'); }
inline bool isexpon(char c) { return (c=='e' || c=='E'); }
inline bool isblank(char c) { return c==' '; }
inline bool ispunct(char c) { return c=='.'; }

bool real_number(string s) {
	int state = 0;

	for ( int i=0 ; i<s.size() ; ++i ) {
		char c = s[i];
		//printf("%d - %c \n", state, c);
		switch ( state ) {
			case 0:
				if ( isdigit(c) ) state = 3;
				else if ( issign(c) ) state = 1;
				else if ( isblank(c) ) state = 2;
				else return false;
				break;
			case 1:
				if ( isdigit(c) ) state = 3;
				else if ( isblank(c) ) state = 2;
				else return false;
				break;
			case 2:
				if ( isdigit(c) ) state = 3;
				else if ( isblank(c) ) state = 2;
				else return false;
				break;
			case 3:
				if ( isdigit(c) ) state = 3;
				else if ( ispunct(c) ) state = 5;
				else if ( isblank(c) ) state = 4;
				else if ( isexpon(c) ) state = 8;
				else return false;
				break;
			case 4:
				if ( isblank(c) ) state = 4;
				else if ( ispunct(c) ) state = 5;
				else if ( isexpon(c) ) state = 8;
				else return false;
				break;
			case 5:
				if ( isblank(c) ) state = 5;
				else if ( isdigit(c) ) state = 6;
				else return false;
				break;
			case 6:
				if ( isdigit(c) ) state = 6;
				else if ( isblank(c) ) state = 7;
				else if ( isexpon(c) ) state = 8;
				else return false;
				break;
			case 7:
				if ( isblank(c) ) state = 7;
				else if ( isexpon(c) ) state = 8;
				else return false;
				break;
			case 8:
				if ( issign(c) ) state = 9;
				else if ( isblank(c) ) state = 8;
				else if ( isdigit(c) ) state = 11;
				else return false;
				break;
			case 9:
				if ( isblank(c) ) state = 10;
				else if ( isdigit(c) ) state = 11;
				else return false;
				break;
			case 10:
				if ( isblank(c) ) state = 10;
				else if ( isdigit(c) ) state = 11;
				else return false;
				break;
			case 11:
				if ( isdigit(c) ) state = 11;
				else if ( isblank(c) ) state = 11;
				else return false;
				break;
			case 12:
				if ( isblank(c) ) state = 12;
				else return false;
				break;
		}
	}
	switch ( state ) {
		case 3:
		case 4:
		case 6:
		case 7:
		case 11:
		case 12:
			return true;
		default:
			return false;
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	cin.ignore(1);
	while ( T-- ) {
		string s;
		getline(cin, s);
		//cout <<"string : "  << s << endl;
		puts(real_number(s)?"LEGAL":"ILLEGAL");
	}
	return 0;
}
