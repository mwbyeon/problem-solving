#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string equ;
		cin >> equ;

		if ( equ[0]!='-' && equ[0]!='+' ) equ = "+" + equ;

		equ += "+0x";
		for ( int i=1 ; i<equ.size() ; ++i ) {
			if ( equ[i]=='x' && (equ[i-1]=='-' || equ[i-1]=='+' || equ[i-1]=='=' ) )
				equ.insert(i, "1");
			else if ( isdigit(equ[i-1]) && (equ[i]=='-' || equ[i]=='+' || equ[i]=='=' ) )
				equ.insert(i, "c");
		}

		int k = equ.find('=');
		if ( isdigit(equ[k+1]) ) {
			equ.replace(k, 1, "+");
		}
		else {
			equ.replace(k, 1, " ");
		}

		for ( int i=k ; i<equ.size() ; ++i ) {
			if ( equ[i]=='-' ) equ[i] = '+';
			else if ( equ[i]=='+' ) equ[i] = '-';
		}

		istringstream sin(equ);
		char sign, x;
		int n;
		int lhs = 0, rhs = 0;
		while ( sin >> sign >> n >> x ) {
			if ( x=='x' ) {
				lhs += (sign=='-'?-1:1)*n;
			}
			else {
				rhs += (sign=='+'?-1:1)*n;
			}
		}
		//cout << equ << ' ' << lhs << ' ' << rhs << endl;

		if ( lhs==0 && rhs==0 ) puts("IDENTITY");
		else if ( lhs==0 && rhs!=0 ) puts("IMPOSSIBLE");
		else {
			printf("%d\n", (int)floor(double(rhs)/double(lhs)));
		}
	}
	return 0;
}
