#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string itos(int n) {
	ostringstream sout;
	sout << n;
	return sout.str();
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string seq, res;

		int i;

		cin >> seq;
		i = 0;
		while ( i<seq.length() ) {
			int cnt = 1;
			while ( i+1<seq.length() && seq[i]==seq[i+1] ) ++cnt, ++i;
			res += itos(cnt);
			res += seq[i];
			++i;
		}
		cout << res << endl;
	}
	return 0;
}
