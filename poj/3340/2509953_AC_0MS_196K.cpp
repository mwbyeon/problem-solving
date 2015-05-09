#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

int pow10(int n) {
	int res = 1;
	while ( n-- ) res *= 10;
	return res;
}

int solve(string a, string b) {
	int res = 0, t1, t2, p, i;

	//cout << "--" << a << ' ' << b << endl;

	if ( a.length()==0 && b.length()==0 ) return 0;
	if ( a.find_first_not_of('?')==string::npos ) { // all '?'
		sscanf(b.c_str(), "%d", &t1);
		return pow10(a.length())-t1-1;
	}
	if ( (p = a.find_first_of('?'))!=string::npos ) {
		t1 = t2 = 0;
		sscanf(a.substr(0,p).c_str(), "%d", &t1);
		sscanf(b.substr(0,p).c_str(), "%d", &t2);
		//printf(" t1 : %d\n t2 : %d\n", t1, t2);
		if ( t1 > t2 )	res = pow10(count(a.begin(), a.end(), '?'));
		if ( t1 == t2 )	res = ('9'-b[p])*pow10(count(a.begin()+p+1, a.end(), '?')) + solve(a.substr(p+1), b.substr(p+1));
		return res;
	}
	return a > b;
}

int main()
{
	string a, b;
	int n;

	while ( cin >> a, a!="#" ) {
		cin >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
