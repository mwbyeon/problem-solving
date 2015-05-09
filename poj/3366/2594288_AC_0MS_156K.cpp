#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string,string> plural;
	map<string,string>::iterator it;
	int L, N;
	string s1, s2, s;
	string consonant("aiueo");

	cin >> L >> N;
	while ( L-- ) {
		cin >> s1 >> s2;
		plural[s1] = s2;
	}

	while ( N-- ) {
		cin >> s;
		if ( (it=plural.find(s))!=plural.end() ) 
			cout << it->second << endl;
		else {
			int len = s.size();
			if ( *s.rbegin()=='y' && consonant.find(*(s.rbegin()+1))==string::npos )
				cout << s.substr(0,len-1)+"ies" << endl;
			else if ( s.substr(len-1)=="o" || s.substr(len-1)=="s" || 
s.substr(len-2)=="ch" || s.substr(len-2)=="sh" || s.substr(len-1)=="x" )
				cout << s+"es" << endl;
			else
				cout << s+"s" << endl;
		}
	}
	return 0;
}
