#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int,string> memo;

string toBin(int n) {
	string& res = memo[n];
	if ( res != "" ) return res;
	res = string(16, '0');
	for ( int i=0 ; i<16 ; ++i ) 
		if ( n&(1<<i) ) res[15-i] = '1';
	return res;
}

int main()
{
	int A, B, C, S;
	while ( scanf("%d", &A), A ) {
		scanf("%d %d %d", &B, &C, &S);

		set<int> already;
		string res( toBin(S) );

		while ( already.find(S)==already.end() ) {
			already.insert(S);
			S = (A*S+B)%C;
			string bin( toBin(S) );
			for ( int i=0 ; i<16 ; ++i ) if ( res[i] != bin[i] ) res[i] = '?';
		}
		cout << res << endl;
	}
	return 0;
}
