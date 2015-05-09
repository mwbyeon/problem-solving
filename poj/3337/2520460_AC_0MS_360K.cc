#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <sstream>
#include <memory>
using namespace std;

string itoa(int n) { ostringstream sout; sout << n; return sout.str(); }

int main()
{
	int T;
	cin >> T;
	cin.ignore(1);
	while ( T-- ) {
		string line;
		getline(cin, line);

		cout << "Expression: " << line << endl;
		while ( line.find(' ')!=string::npos ) line.replace(line.find(' '), 1, "");

		bool used['z'+1];
		memset(used, 0, sizeof(used));
		for ( int i=0 ; i<line.size() ; ++i ) 
			if ( islower(line[i]) ) used[line[i]] = true;

		int var['z'+1];
		for ( int i='a' ; i<='z' ; ++i ) var[i] = i-'a'+1;

		int p;
		while ( (p=line.find("++"))!=string::npos ) {
			if ( p>=1 && islower(line[p-1]) ) { // a++
				line.replace(p-1, 3, itoa(var[line[p-1]]++));
			}
			else { // ++a
				line.replace(p, 3, itoa(++var[line[p+2]]));
			}
		}
		while ( (p=line.find("--"))!=string::npos ) {
			if ( p>=1 && islower(line[p-1]) ) { // a--
				line.replace(p-1, 3, itoa(var[line[p-1]]--));
			}
			else { // --a
				line.replace(p, 3, itoa(--var[line[p+2]]));
			}
		}

		for ( int i=0 ; i<line.size() ; ++i ) 
			if ( islower(line[i]) ) 
				line.replace(i, 1, itoa(var[line[i]]));

		if ( !ispunct(line[0]) ) line = '+' + line;

		char sign;
		int val, sum=0;
		
		istringstream sin(line);
		while ( sin >> sign >> val ) {
			if ( sign=='+' ) sum += val;
			else sum -= val;
		}
		cout << "value = " << sum << endl;
		for ( int i='a' ; i<='z' ; ++i )
			if ( used[i] ) 
				cout << (char)i << " = " << var[i] << endl;

	}
	return 0;
}
