#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

void print(int n) {
	if ( n==0 ) {
		printf("{}");
		return;
	}
	printf("{");
	int i;
	for ( i=0 ; i<n-1 ; ++i ) {
		print(i);
		printf(",");
	}
	print(i);
	printf("}");
}

int getNum(string& s) {
	int i = s.length()-1;
	int res = 0;
	while ( s[i]=='}' ) --i, ++res;
	return res-1;
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		string n1, n2;
		cin >> n1 >> n2;
		print(getNum(n1)+getNum(n2));
		puts("");
	}
	return 0;
}
