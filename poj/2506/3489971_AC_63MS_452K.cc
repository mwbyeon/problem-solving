#include <iostream>
#include <algorithm>
using namespace std;

string add(string s1, string s2)
{
	string res;
	int len = s1.length() >? s2.length();
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	s1.resize(len, '0');
	s2.resize(len, '0');

	int carry = 0, num;
	for ( int i=0 ; i<len ; ++i ) {
		num = s1[i]+s2[i]-'0'-'0'+carry;
		if ( num > 9 ) {
			num -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		res = char(num+'0') + res;
	}
	if ( carry ) res = "1" + res;
	return res;
}

int main()
{
	string table[251] = { "1", "1", "3" };
	for ( int i=2 ; i<251 ; ++i ) {
		//table[i] = table[i-1] + table[i-2] + table[i-2];
		table[i] = add(table[i-2], table[i-2]);
		table[i] = add(table[i-1], table[i]);		
	}

	int n;
	while ( cin >> n ) {
		cout << table[n] << endl;
	}

	return 0;
}
