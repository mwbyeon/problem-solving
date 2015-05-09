// critical data : Fei  iei eie

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	string line;
	int p;
	while ( getline(cin, line) ) {
		string res;
		int len = line.length();

		line += "!!!!!!!!!!";
		for ( int i=0 ; i<len ; ) {
			if ( line[i]=='E' && line[i+1]=='O' && line[i+2]=='F' ) {
				if ( res!="" ) cout << res << endl;
				return 0;
			}
			else if ( line[i]=='d' && line[i+1]=='d' ) {
				cout << 'p';
				i +=2 ;
			}
			else if ( line[i]=='p' && line[i+1]=='i' && line[i+2]=='n' && line[i+3]=='k' ) {
				cout << "floyd";
				i += 4;
			}
			else if ( line[i]=='e' && line[i+1]=='i' ) {
				if ( i==0 ) {
					cout << "ie";
					i += 2;
				}
				else if ( line[i-1]!='c' ) {
					cout << "ie";
					i += 2;
				}
				else {
					cout << "ei";
					i += 2;
				}
			}
			else if ( islower(line[i]) || line[i]==' ' ) {
				cout << line[i];
				i += 1;
			}
			else ++i;
		}
		cout << endl;
	}
	return 0;
}


